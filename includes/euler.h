/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:40:09 by jleem             #+#    #+#             */
/*   Updated: 2021/01/25 19:59:50 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EULER_H
# define EULER_H

# ifndef PI
#  define PI 3.14159265358979323846264338327950288f
# endif
# define PI_180 0.01745329251994329576923690768488612f
# include "vector.h"

void	vec3_to_euler(t_vec3 e_v, float *out_yaw, float *out_pitch);
t_vec3	euler_to_vec3(float yaw, float pitch);
t_vec3	vec3_move_euler(t_vec3 e_v, float delta_yaw, float delta_pitch);

#endif
