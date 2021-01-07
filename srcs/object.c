/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:29:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/08 07:42:02 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object			make_sphere(t_vec3 location, float radius, int color)
{
	t_object	object;

	object.location = location;
	object.type = obj_type_sphere;
	object.radius = radius;
	object.color = color;

	return (object);
}
