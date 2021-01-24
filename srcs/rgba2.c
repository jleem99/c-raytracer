/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:54:00 by jleem             #+#    #+#             */
/*   Updated: 2021/01/24 20:26:47 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgba.h"

int		rgba_blend(int rgba1, int rgba2, float alpha)
{
	return (rgba(
		(rgba_r(rgba1) - rgba_r(rgba2)) * alpha + rgba_r(rgba2),
		(rgba_g(rgba1) - rgba_g(rgba2)) * alpha + rgba_g(rgba2),
		(rgba_b(rgba1) - rgba_b(rgba2)) * alpha + rgba_b(rgba2),
		(rgba_a(rgba1) - rgba_a(rgba2)) * alpha + rgba_a(rgba2)
	));
}

int		rgba_multiply(int rgba_, float k)
{
	return (rgba(
		rgba_r(rgba_) * k,
		rgba_g(rgba_) * k,
		rgba_b(rgba_) * k,
		rgba_a(rgba_) * k
	));
}
