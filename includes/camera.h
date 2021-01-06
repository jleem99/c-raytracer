/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:59:04 by jleem             #+#    #+#             */
/*   Updated: 2021/01/07 00:42:14 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

// To do: Change forward, up, right into Yaw, Pitch, Roll
typedef struct	s_camera
{
	t_vec3		origin;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;
	float		fov;
	float		aspect_ratio;
	float		focal_length;
	t_vec2		screen_dimension;
	t_vec2i		viewport_dimension;
}				t_camera;

t_camera		make_camera(t_vec3 origin, t_vec3 fw, t_vec3 up, float fov, t_vec2i vp);

#endif
