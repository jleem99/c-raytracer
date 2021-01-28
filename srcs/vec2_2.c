/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:47:40 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 01:01:19 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

float			vec2_square(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

float			vec2_length(t_vec2 v)
{
	return (sqrtf(vec2_square(v)));
}

t_vec2			vec2_norm(t_vec2 v)
{
	t_vec2		ret;
	float const	w = vec2_length(v);

	ret.x = v.x / w;
	ret.y = v.y / w;
	return (ret);
}
