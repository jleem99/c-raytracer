/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:29:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 02:32:31 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <stdlib.h>

t_object			*make_sphere(t_vec3 location, float radius, int color)
{
	t_object	*object;

	if (!(object = malloc(sizeof(t_object))))
		return (NULL);
	object->location = location;
	object->type = obj_type_sphere;
	object->radius = radius;
	object->color = color;
	return (object);
}

t_object			*make_plane(t_vec3 location, t_vec3 normal, int color)
{
	t_object	*object;

	if (!(object = malloc(sizeof(t_object))))
		return (NULL);
	object->location = location;
	object->type = obj_type_plane;
	object->forward = vec3_normalize(normal);
	object->color = color;
	return (object);
}
