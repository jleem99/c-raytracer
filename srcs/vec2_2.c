/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:47:40 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 23:50:57 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2			make_vec2(float x, float y)
{
	t_vec2	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

float			vec2_square(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

t_vec2			vec2_multiply(t_vec2 v, float k)
{
	t_vec2	ret;

	ret.x = v.x * k;
	ret.y = v.y * k;
	return (ret);
}
