/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:07:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/07 01:01:47 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include <stddef.h>
# include "scene.h"
# include "ray.h"
# include "camera.h"

typedef struct	s_trace
{
	t_scene		*scene;
	t_ray		*ray;
	int			color;
	size_t		count;
}				t_trace;

t_trace			*raytrace(t_trace *trace);
void			raytrace_with_camera(t_trace *trace, t_camera *camera, void *fp(int, int, int));

#endif
