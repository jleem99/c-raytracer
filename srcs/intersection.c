/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:30:27 by jleem             #+#    #+#             */
/*   Updated: 2021/01/30 12:35:19 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include <math.h>
#include <stdlib.h>

t_hit	get_ray_intersection_from_object(t_ray const *ray, t_object const *obj)
{
	t_hit			ret;

	ret.object = obj;
	if (obj->type == obj_type_sphere)
	{
		t_vec3 const	d = vec3_sub(obj->location, ray->origin);
		t_vec3 const	r_unit = vec3_norm(ray->forward);
		float const		d_flat = vec3_dot(r_unit, d);
		float const		e = obj->radius * obj->radius - (vec3_square(d) - d_flat * d_flat);

		if (e > 0)
		{
			ret.location = vec3_mul(r_unit, d_flat - sqrtf(e));
			if (vec3_dot(ret.location, ray->forward) <= 0)
				return (hit_zero());
			ret.distance = vec3_length(ret.location);
			ret.location = vec3_add(ray->origin, ret.location);
			return (ret);
		}
	}
	else if (obj->type == obj_type_plane)
	{
		float tmp = vec3_dot(obj->forward, vec3_sub(ray->origin, obj->location));

		if (tmp * vec3_dot(obj->forward, ray->forward) < 0)
		{
			ret.location = vec3_mul(ray->forward, - tmp / vec3_dot(obj->forward, ray->forward));
			ret.distance = vec3_length(ret.location);
			ret.location = vec3_add(ret.location, ray->origin);
			return (ret);
		}
	}
	return (hit_zero());
}

t_hit	get_ray_intersection_from_scene(t_trace *trace, t_scene const *scene)
{
	t_ray	const	*ray = trace->ray;
	t_hit			ret;
	size_t			i;

	ret.object = NULL;
	ret.distance = 0;
	if (scene->objects->size == 0)
		return (ret);
	i = 0;
	while (i < scene->objects->size)
	{
		trace->hits[i] = get_ray_intersection_from_object(ray, scene->objects->data[i]);
		i++;
	}
	i = 0;
	while (i < scene->objects->size)
	{
		if (!ret.object || (trace->hits[i].object && ret.distance > trace->hits[i].distance))
			ret = trace->hits[i];
		i++;
	}
	return (ret);
}
