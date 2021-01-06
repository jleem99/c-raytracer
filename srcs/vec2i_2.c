/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:08:47 by jleem             #+#    #+#             */
/*   Updated: 2021/01/07 00:08:49 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2i			make_vec2i(int x, int y)
{
	t_vec2i	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

int				vec2i_square(t_vec2i v)
{
	return (v.x * v.x + v.y * v.y);
}

t_vec2i			vec2i_multiply(t_vec2i v, int k)
{
	t_vec2i	ret;

	ret.x = v.x * k;
	ret.y = v.y * k;
	return (ret);
}
