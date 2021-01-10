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

t_trace			*raytrace(t_trace *trace)
{
	t_hit	hit;
	
	hit = get_ray_intersection_from_scene(trace->ray, trace->scene);
	if (hit.object)
		trace->color = hit.object->color;
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
	t_vec3		temp;

	trace->ray->origin = camera->origin;
	for (index.y = height - 1; index.y >= 0; index.y--)
	{
		for (index.x = 0; index.x < width; index.x++)
		{
			index_unit.x = (float)index.x / (float)(width - 1);		// 0 to 1
			index_unit.y = (float)index.y / (float)(height - 1);	// 0 to 1

			trace->ray->forward = camera->forward;
			temp = vec3_multiply(&camera->right, index_unit.x - 0.5);
			trace->ray->forward = vec3_add(&trace->ray->forward, &temp);
			temp = vec3_multiply(&camera->up, index_unit.y - 0.5);
			trace->ray->forward = vec3_add(&trace->ray->forward, &temp);
			trace->count = 1;
			raytrace(trace);
			put_pixel(index.x, index.y, trace->color);
		}
	}
}
