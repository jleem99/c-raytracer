/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:19:13 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 19:09:43 by jleem            ###   ########.fr       */
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
	camera->screen_dimension = make_vec2(2 * aspect_ratio, 2);
	camera->viewport_dimension = vp;
	camera->forward = vec3_multiply(vec3_normalize(fw), camera->focal_length);
	camera->up = vec3_normalize(up);
	camera->up = vec3_multiply(camera->up, camera->screen_dimension.y);
	camera->right = vec3_normalize(vec3_cross_product(fw, up));
	camera->right = vec3_multiply(camera->right, camera->screen_dimension.x);
	return (camera);
}
