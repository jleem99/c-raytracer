/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:00:36 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 18:20:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec3			make_vec3(float x, float y, float z)
{
	t_vec3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec3			vec3_multiply(t_vec3 v, float k)
{
	t_vec3	ret;

	ret.x = v.x * k;
	ret.y = v.y * k;
	ret.z = v.z * k;
	return (ret);
}


float			vec3_square(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float			vec3_length(t_vec3 v)
{
	return (sqrtf(vec3_square(v)));
}
