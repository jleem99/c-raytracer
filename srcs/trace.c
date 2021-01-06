/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:36:39 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 16:58:38 by jleem            ###   ########.fr       */
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
		trace->color = 0xDDDDFFFF;
	trace->count--;

	if (trace->count == 0)
		return (trace);
	else
		return (raytrace(trace));
}
