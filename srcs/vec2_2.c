/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:47:40 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 18:20:30 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec2			make_vec2(float x, float y)
{
	t_vec2	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_vec2			vec2_multiply(t_vec2 v, float k)
{
	t_vec2	ret;

	ret.x = v.x * k;
	ret.y = v.y * k;
	return (ret);
}

float			vec2_square(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

float			vec2_length(t_vec2 v)
{
	return (sqrtf(vec2_square(v)));
}
