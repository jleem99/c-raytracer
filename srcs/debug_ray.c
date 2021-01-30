/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 03:31:22 by jleem             #+#    #+#             */
/*   Updated: 2021/01/30 13:23:50 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "debug.h"
// #include "img.h"

// t_engine	*g_engine;
// void		(*g_debug_put_pixel)(int x, int y, int color);

// void	init_debug(void (*fp)(int, int, int))
// {
// 	g_debug_put_pixel = fp;
// }

// void	debug_point(t_vec3 v)
// {
// 	t_camera const	*camera = scene_get_camera(g_engine->scene, 0);
// 	t_vec3 const	f = camera->forward;
// 	t_vec3 const	o = camera->origin;
// 	float const		t = vec3_dot(f, vec3_add(o, f)) / vec3_dot(f, v);

// 	if (t < 0) return ;
// 	t_vec3 const	delta = vec3_sub(vec3_mul(v, t), f);

// 	float k_x = vec3_dot(delta, camera->right) + 0.5f;
// 	float k_y = 0.5f - vec3_dot(delta, camera->up);

// 	if (0.f <= k_x <= 1.f && 0.f <= k_y <= 1.f)
// 		g_debug_put_pixel(
// 			camera->viewport_dimension.x * k_x,
// 			camera->viewport_dimension.y * k_y,
// 			0xFFFF0000
// 		);
// }

// void	debug_ray(t_ray *ray)
// {
// 	float	t;

// 	t = 0;
// 	while (t <= 10)
// 	{
// 		debug_point(ray_at(ray, t));
// 		t += 0.1f;
// 	}
// }