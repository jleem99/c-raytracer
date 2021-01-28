/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:19:13 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 00:56:53 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <stdlib.h>
#include <math.h>

t_camera		*make_camera(t_vec3 origin, t_vec3 fw, t_vec3 up, float fov, t_vec2i vp)
{
	t_camera	*camera;
	float const	aspect_ratio = (float)vp.x / (float)vp.y;

	if (!(camera = malloc(sizeof(t_camera))))
		return (NULL);
	camera->origin = origin;
	camera->fov = fov;
	camera->aspect_ratio = aspect_ratio;
	camera->focal_length = 1 / tanf(fov / 2);
	camera->screen_dimension = vec2(2 * aspect_ratio, 2);
	camera->viewport_dimension = vp;
	camera->forward = vec3_mul(vec3_norm(fw), camera->focal_length);
	camera->up = vec3_norm(up);
	camera->up = vec3_mul(camera->up, camera->screen_dimension.y);
	camera->right = vec3_norm(vec3_cross(up, fw));
	camera->right = vec3_mul(camera->right, camera->screen_dimension.x);
	return (camera);
}
