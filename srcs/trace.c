/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:36:39 by jleem             #+#    #+#             */
/*   Updated: 2021/01/25 20:37:11 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "object.h"
#include "hit.h"
#include "intersection.h"
#include <stdio.h>
#include <math.h>
#include "rgba.h"
static t_trace	*raytrace(t_trace *trace)
{
	t_hit	hit;

	hit = get_ray_intersection_from_scene(trace);
	if (hit.object)
	{
		t_vec3 normal = vec3_normalize(vec3_subtract(hit.location, hit.object->location));
		float dot = vec3_dot(normal, vec3_normalize(make_vec3(-0.5, -0.6, 1)));
		float luminance = (dot + 1) / 2;

		trace->color = rgba_blend(
			rgba_multiply(hit.object->color, luminance), trace->color, 0.5f
		);

		if (trace->count > 1)
			trace->ray->forward = vec3_reflect(trace->ray->forward, normal);
	}
	else
		trace->color = rgba_blend(0xFFCDFFFC, trace->color, 0.5f);
	trace->count--;

	if (trace->count == 0)
		return (trace);
	else
		return (raytrace(trace));
}
#include <stdlib.h>
void			raytrace_with_camera(t_trace *trace, t_camera *camera, void *put_pixel(int, int, int))
{
	int const	width = camera->viewport_dimension.x;
	int const	height = camera->viewport_dimension.y;
	t_vec2i		index;
	t_vec2		index_unit;

	if (!(trace->hits = malloc(sizeof(t_hit) * trace->scene->objects->size)))
		return ;
	trace->ray->origin = camera->origin;
	for (index.y = 0; index.y < height; index.y++)
	{
		for (index.x = 0; index.x < width; index.x++)
		{
			index_unit.x = (float)index.x / (float)(width - 1);		// 0 to 1
			index_unit.y = (float)index.y / (float)(height - 1);	// 0 to 1

			trace->ray->forward = camera->forward;
			trace->ray->forward = vec3_add(trace->ray->forward,
									vec3_multiply(camera->right, 0.5f - index_unit.x));
			trace->ray->forward = vec3_add(trace->ray->forward,
									vec3_multiply(camera->up, 0.5f - index_unit.y));
			trace->count = 1;
			raytrace(trace);
			put_pixel(index.x, index.y, trace->color);
		}
	}
	free(trace->hits);
}
