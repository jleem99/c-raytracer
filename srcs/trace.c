/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: index.yleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:36:39 by jleem             #+#    #+#             */
/*   Updated: 2021/01/07 00:17:51 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "object.h"
#include "hit.h"
#include "intersection.h"
#include <stdio.h>
#include <math.h>
t_trace			*raytrace(t_trace *trace)
{
	t_hit	hit;
	
	hit = get_ray_intersection_from_scene(trace->ray, trace->scene);
	if (hit.object)
	{
		int a = (hit.object->color & (0xFF << 24)) >> 24;
		int r = (hit.object->color & (0xFF << 16)) >> 16;
		int g = (hit.object->color & (0xFF << 8)) >> 8;
		int b = (hit.object->color & 0xFF);
		// printf("%d,%d,%d,%d - ", a, r, g, b);
		t_vec3 normal = vec3_subtract(hit.location, hit.object->location);
		float dot = vec3_dot(
			vec3_normalize(normal),
			vec3_normalize(make_vec3(0.5, 0.6, -1))
		);
		float luminance = (dot + 1) / 2;
		// printf("%f\n", luminance);
		a *= luminance;
		r *= luminance;
		g *= luminance;
		b *= luminance;
		// printf("%d,%d,%d,%d\n", a, r, g, b);
		trace->color = (a << 24) | (r << 16) | (g << 8) | b;
		// trace->color = hit.object->color;
	}
	else
		trace->color = 0xffcdfffc;
	trace->count--;

	if (trace->count == 0)
		return (trace);
	else
		return (raytrace(trace));
}

void			raytrace_with_camera(t_trace *trace, t_camera *camera, void *put_pixel(int, int, int))
{
	int const	width = camera->viewport_dimension.x;
	int const	height = camera->viewport_dimension.y;
	t_vec2i		index;
	t_vec2		index_unit;

	trace->ray->origin = camera->origin;
	for (index.y = 0; index.y < height; index.y++)
	{
		for (index.x = 0; index.x < width; index.x++)
		{
			index_unit.x = (float)index.x / (float)(width - 1);		// 0 to 1
			index_unit.y = 1.f - (float)index.y / (float)(height - 1);	// 0 to 1

			trace->ray->forward = camera->forward;
			trace->ray->forward = vec3_add(trace->ray->forward,
									vec3_multiply(camera->right, index_unit.x - 0.5));
			trace->ray->forward = vec3_add(trace->ray->forward,
									vec3_multiply(camera->up, index_unit.y - 0.5));
			trace->count = 1;
			raytrace(trace);
			put_pixel(index.x, index.y, trace->color);
		}
	}
}
