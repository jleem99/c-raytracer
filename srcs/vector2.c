/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:00:36 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 15:48:24 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		make_vector(float x, float y, float z)
{
	t_vector	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

float			square_vector(t_vector vect)
{
	return (vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
}

t_vector		multiply_vector(t_vector vect, float k)
{
	t_vector	ret;

	ret.x = vect.x * k;
	ret.y = vect.y * k;
	ret.z = vect.z * k;
	return (ret);
}
