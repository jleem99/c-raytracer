/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:38:58 by jleem             #+#    #+#             */
/*   Updated: 2021/01/11 00:15:41 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec3			vec3_add(t_vec3 *u, t_vec3 *v)
{
	t_vec3	ret;

	ret.x = u->x + v->x;
	ret.y = u->y + v->y;
	ret.z = u->z + v->z;
	return (ret);
}

t_vec3			vec3_subtract(t_vec3 *u, t_vec3 *v)
{
	t_vec3	ret;

	ret.x = u->x - v->x;
	ret.y = u->y - v->y;
	ret.z = u->z - v->z;
	return (ret);
}

t_vec3			vec3_normalize(t_vec3 *v)
{
	t_vec3		ret;
	float const w = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);

	ret.x = v->x / w;
	ret.y = v->y / w;
	ret.z = v->z / w;
	return (ret);
}

float			vec3_dot_product(t_vec3 *u, t_vec3 *v)
{
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_vec3			vec3_cross_product(t_vec3 *u, t_vec3 *v)
{
	t_vec3	ret;

	ret.x = u->y * v->z - u->z * v->y;
	ret.y = u->z * v->x - u->x * v->z;
	ret.z = u->x * v->y - u->y * v->x;
	return (ret);
}
