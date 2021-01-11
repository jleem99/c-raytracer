/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:47:29 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 03:19:09 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec2			vec2_add(t_vec2 u, t_vec2 v)
{
	t_vec2	ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;
	return (ret);
}

t_vec2			vec2_subtract(t_vec2 u, t_vec2 v)
{
	t_vec2	ret;

	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	return (ret);
}

t_vec2			vec2_normalize(t_vec2 v)
{
	t_vec2		ret;
	float const	w = sqrtf(v.x * v.x + v.y * v.y);

	ret.x = v.x / w;
	ret.y = v.y / w;
	return (ret);
}

float			vec2_dot(t_vec2 u, t_vec2 v)
{
	return (u.x * v.x + u.y * v.y);
}
