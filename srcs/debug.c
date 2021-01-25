/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:18:29 by jleem             #+#    #+#             */
/*   Updated: 2021/01/25 20:19:48 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	vec3_print(t_vec3 v)
{
	printf("(%f, %f, %f)\n", v.x, v.y, v.z);
}

void	vec2_print(t_vec2 v)
{
	printf("(%f, %f)\n", v.x, v.y);
}

void	vec2i_print(t_vec2i v)
{
	printf("(%d, %d, %d)\n", v.x, v.y);
}
