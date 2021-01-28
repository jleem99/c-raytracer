/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:08:47 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 01:01:32 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

int				vec2i_square(t_vec2i v)
{
	return (v.x * v.x + v.y * v.y);
}

float			vec2i_length(t_vec2i v)
{
	return (sqrtf(vec2i_square(v)));
}
