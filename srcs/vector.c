/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:38:58 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 14:16:48 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "math.h"

t_vector		add_vector(t_vector vect1, t_vector vect2)
{
	t_vector	ret;

	ret.x = vect1.x + vect2.x;
	ret.y = vect1.y + vect2.y;
	ret.z = vect1.z + vect2.z;
	return (ret);
}

t_vector		subtract_vector(t_vector vect1, t_vector vect2)
{
	t_vector	ret;

	ret.x = vect1.x - vect2.x;
	ret.y = vect1.y - vect2.y;
	ret.z = vect1.z - vect2.z;
	return (ret);
}

t_vector		normalize_vector(t_vector v)
{
	t_vector	ret;
	float const w = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	ret.x = v.x / w;
	ret.y = v.y / w;
	ret.z = v.z / w;
	return (ret);
}

float			dot_product(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector		cross_product(t_vector u, t_vector v)
{
	t_vector	ret;

	ret.x = u.y * v.z - u.z * v.y;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - u.y * v.x;
	return (ret);
}
