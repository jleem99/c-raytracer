/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:08:36 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 03:19:09 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec2i			vec2i_add(t_vec2i u, t_vec2i v)
{
	t_vec2i	ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;
	return (ret);
}

t_vec2i			vec2i_subtract(t_vec2i u, t_vec2i v)
{
	t_vec2i	ret;

	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	return (ret);
}

int				vec2i_dot(t_vec2i u, t_vec2i v)
{
	return (u.x * v.x + u.y * v.y);
}
