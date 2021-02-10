/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:36:39 by jleem             #+#    #+#             */
/*   Updated: 2021/02/02 01:04:57 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "engine.h"
#include "object.h"
#include "hit.h"
#include "intersection.h"
#include "rgba.h"
#include "debug.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static t_trace	*raytrace(t_trace *trace, t_scene *scene)
{
	t_hit const	hit = get_ray_intersection_from_scene(trace, scene);

	if (hit.object)
	{
		if (hit.object->type == obj_type_plane)
		{
			trace->ray->origin = hit.location;
			trace->ray->forward = vec3(-0.5, -0.6, 1);
			trace->ray->origin = vec3_add(trace->ray->origin, vec3_mul(trace->ray->forward, 0.1f));
			if (get_ray_intersection_from_scene(trace, scene).object)
			{
				trace->color = 0;
				return (trace);
			}
			trace->color = hit.object->color;
			return (trace);
		}

		trace->ray->origin = hit.location;
		trace->ray->forward = vec3(-0.5, -0.6, 1);
		trace->ray->origin = vec3_add(trace->ray->origin, vec3_mul(trace->ray->forward, -0.1f));
		if (get_ray_intersection_from_scene(trace, scene).object)
		{
			trace->color = 0;
			return (trace);
		}

		t_vec3 normal = vec3_norm(vec3_sub(hit.location, hit.object->location));
		float dot = vec3_dot(normal, vec3_norm(vec3(-0.5, -0.6, 1)));
		float luminance = (dot + 1) / 2;
		luminance = luminance * luminance;

		// trace->color = rgba_blend(
		// 	rgba_multiply(hit.object->color, luminance), trace->color, 0.5f
		// );
		trace->color = rgba_multiply(hit.object->color, luminance);

		if (trace->count > 1)
		{
			trace->ray->origin = hit.location;
			trace->ray->forward = vec3_reflect(trace->ray->forward, normal);
		}
	}
	else
	{
		// trace->color = rgba_blend(0xFFCDFFFC, trace->color, 0.5f);
		trace->color = 0xFFCDFFFC;
		return (trace);
	}
	trace->count--;

	if (trace->count == 0)
		return (trace);
	else
		return (raytrace(trace, scene));
}

static void		raytrace_pixel(t_trace *trace, t_scene *scene, float x, float y)
{
	t_camera const	*camera = scene_get_camera(scene, 0);

	trace->ray->origin = camera->origin;
	trace->ray->forward = camera->forward;
	trace->ray->forward =
		vec3_add(trace->ray->forward, vec3_mul(camera->right, x - 0.5f));
	trace->ray->forward =
		vec3_add(trace->ray->forward, vec3_mul(camera->up, 0.5f - y));
	trace->color = 0xFFFFFFFF;
	trace->count = 1;
	raytrace(trace, scene);
}

#include <pthread.h>
static void		*raytrace_runner(void *arg)
{
	t_runner_param	*param = arg;
	t_camera const	*camera = scene_get_camera(param->engine->scene, 0);
	int const		width = camera->viewport_dimension.x;
	int const		height = camera->viewport_dimension.y;
	t_vec2i			index;

	int const		hstart = height * param->thread_index / param->engine->thread_count + 1;
	int const		hend = height * (param->thread_index + 1) / param->engine->thread_count;
	printf("[thread %d] hstart / hend: %d / %d\n", param->thread_index, hstart, hend);

	for (index.y = hstart; index.y < hend; index.y++)
	{
		for (index.x = 0; index.x < width; index.x++)
		{
			raytrace_pixel(
				param->trace,
				param->engine->scene,
				(float)index.x / (width - 1),
				(float)index.y / (height - 1)
			);
			param->engine->put_pixel(index.x, index.y, param->trace->color);
		}
	}
	pthread_exit(0);
}

void			raytrace_frame(t_engine *engine)
{
	t_runner_param	*params = malloc(sizeof(t_runner_param) * engine->thread_count); // check
	pthread_t		*tid = malloc(sizeof(pthread_t) * engine->thread_count); // check
	int				i;
	// set_debug_engine(engine);
	i = 0;
	while (i < engine->thread_count)
	{
		params[i].trace = engine->traces[i];
		params[i].trace->hits = malloc(sizeof(t_hit) * engine->scene->objects->size); // check
		params[i].engine = engine;
		params[i].thread_index = i;
		pthread_create(&tid[i], NULL, raytrace_runner, &params[i]);
		i++;
	}
	i = 0;
	while (i < engine->thread_count)
		pthread_join(tid[i++], NULL);
	i = 0;
	while (i < engine->thread_count)
		free(params[i++].trace->hits);
	free(params);
	free(tid);
}
