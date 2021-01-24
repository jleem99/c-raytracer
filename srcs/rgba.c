/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 01:21:42 by jleem             #+#    #+#             */
/*   Updated: 2021/01/20 01:33:01 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgba.h"

int		rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int		rgba_r(int rgba)
{
	return ((rgba & (0xFF << 16)) >> 16);
}

int		rgba_g(int rgba)
{
	return ((rgba & (0xFF << 8)) >> 8);
}

int		rgba_b(int rgba)
{
	return (rgba & 0xFF);
}

int		rgba_a(int rgba)
{
	return ((rgba & (0xFF << 24)) >> 24);
}
