/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:19:13 by jleem             #+#    #+#             */
/*   Updated: 2021/01/07 01:42:54 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

t_camera		make_camera(t_vec3 origin, t_vec3 fw, t_vec3 up, float fov, t_vec2i vp)
{
	t_camera	ret;
	float const	aspect_ratio = (float)vp.x / (float)vp.y;
	
	ret.origin = origin;
	ret.fov = fov;
	ret.aspect_ratio = aspect_ratio;
	ret.focal_length = 1 / tanf(fov / 2);
	ret.screen_dimension = make_vec2(2 * aspect_ratio, 2);
	ret.viewport_dimension = vp;
	ret.forward = vec3_multiply(vec3_normalize(fw), ret.focal_length);
	ret.up = vec3_normalize(up);
	ret.up = vec3_multiply(ret.up, ret.screen_dimension.y);
	ret.right = vec3_normalize(vec3_cross_product(fw, up));
	ret.right = vec3_multiply(ret.right, ret.screen_dimension.x);
	return (ret);
}
