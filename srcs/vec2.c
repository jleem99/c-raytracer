/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:47:29 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 01:01:04 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2			vec2(float x, float y)
{
	t_vec2	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_vec2			vec2_add(t_vec2 u, t_vec2 v)
{
	t_vec2	ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;
	return (ret);
}

t_vec2			vec2_sub(t_vec2 u, t_vec2 v)
{
	t_vec2	ret;

	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	return (ret);
}

t_vec2			vec2_mul(t_vec2 v, float k)
{
	t_vec2	ret;

	ret.x = v.x * k;
	ret.y = v.y * k;
	return (ret);
}

float			vec2_dot(t_vec2 u, t_vec2 v)
{
	return (u.x * v.x + u.y * v.y);
}
