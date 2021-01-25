/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:39:08 by jleem             #+#    #+#             */
/*   Updated: 2021/01/25 19:59:53 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "euler.h"
#include <math.h>

void	vec3_to_euler(t_vec3 e_v, float *out_yaw, float *out_pitch)
{
	*out_yaw = atan2f(e_v.y, e_v.x);
	*out_pitch = asinf(e_v.z);
}

t_vec3	euler_to_vec3(float yaw, float pitch)
{
	return (make_vec3(
		cosf(yaw) * cosf(pitch),
		sinf(yaw) * cosf(pitch),
		sinf(pitch)
	));
}

t_vec3	vec3_move_euler(t_vec3 e_v, float delta_yaw, float delta_pitch)
{
	delta_yaw += atan2f(e_v.y, e_v.x);
	delta_pitch += asinf(e_v.z);
	return (euler_to_vec3(delta_yaw, delta_pitch));
}
