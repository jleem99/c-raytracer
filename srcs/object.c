/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:29:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 18:58:10 by jleem            ###   ########.fr       */
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
