/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:00:36 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 00:59:33 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

float			vec3_square(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float			vec3_length(t_vec3 v)
{
	return (sqrtf(vec3_square(v)));
}

t_vec3			vec3_norm(t_vec3 v)
{
	t_vec3		ret;
	float const w = vec3_length(v);

	ret.x = v.x / w;
	ret.y = v.y / w;
	ret.z = v.z / w;
	return (ret);
}

t_vec3			vec3_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	ret;

	ret.x = u.y * v.z - u.z * v.y;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - u.y * v.x;
	return (ret);
}

t_vec3			vec3_reflect(t_vec3 v, t_vec3 e_n)
{
	return (vec3_sub(
		v, vec3_mul(e_n, 2 * vec3_dot(v, e_n))
	));
}
