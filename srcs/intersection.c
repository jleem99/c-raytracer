/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:30:27 by jleem             #+#    #+#             */
/*   Updated: 2021/01/14 17:50:24 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
t_hit			get_ray_intersection_from_object(t_ray *ray, t_object *obj)
{
	t_hit			ret;

	ret.object = obj;
	if (obj->type == obj_type_sphere)
	{
		t_vec3 const	d = vec3_subtract(obj->location, ray->origin);
		t_vec3 const	r_unit = vec3_normalize(ray->forward);
		float const		d_flat = vec3_dot(r_unit, d);
		float const		e = obj->radius * obj->radius - (vec3_square(d) - d_flat * d_flat);

		if (e > 0)
		{
			ret.location = vec3_multiply(r_unit, d_flat - sqrtf(e));
			ret.distance = vec3_length(ret.location);
			ret.location = vec3_add(ray->origin, ret.location);
			return (ret);
		}
	}
	else if (obj->type == obj_type_plane)
	{
		float tmp = vec3_dot(obj->forward, vec3_subtract(ray->origin, obj->location));

		if (tmp * vec3_dot(obj->forward, ray->forward) < 0)
		{
			ret.location = vec3_multiply(ray->forward, - tmp / vec3_dot(obj->forward, ray->forward));
			ret.distance = vec3_length(ret.location);
			ret.location = vec3_add(ret.location, ray->origin);
			return (ret);
		}
	}
	return (hit_zero());
}

t_hit			get_ray_intersection_from_scene(t_ray *ray, t_scene *scene)
{
	t_hit	ret;
	t_hit	*hits;
	size_t	i;

	ret.object = NULL;
	ret.distance = 0;
	if (scene->objects->size == 0 ||
		!(hits = malloc(sizeof(*hits) * scene->objects->size)))
		return (ret);
	i = 0;
	while (i < scene->objects->size)
	{
		hits[i] = get_ray_intersection_from_object(ray, scene->objects->data[i]);
		i++;
	}
	i = 0;
	while (i < scene->objects->size)
	{
		if (!ret.object || (hits[i].object && ret.distance > hits[i].distance))
			ret = hits[i];
		i++;
	}
	free(hits);
	return (ret);
}
