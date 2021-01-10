/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:30:27 by jleem             #+#    #+#             */
/*   Updated: 2021/01/11 00:19:26 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
t_hit			get_ray_intersection_from_object(t_ray *ray, t_object *obj)
{
	t_hit			ret;
	t_vec3 	r_unit = vec3_normalize(&ray->forward);
	t_vec3 	d = vec3_subtract(&obj->location, &ray->origin);
	float 		d_flat = vec3_dot_product(&r_unit, &d);
	float 		e = obj->radius * obj->radius - (vec3_square(&d) - d_flat * d_flat);

	if (obj->type == obj_type_sphere && e > 0)
	{
		ret.object = obj;
		ret.location = vec3_multiply(&r_unit, d_flat - sqrtf(e));
		ret.distance = vec3_length(&ret.location);
		ret.location = vec3_add(&ray->origin, &ret.location);
	}
	else
	{
		ret.object = NULL;
		// ret.location = make_vec3(0, 0, 0);
		ret.distance = 0;
	}
	return (ret);
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
