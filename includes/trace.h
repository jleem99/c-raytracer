/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:07:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/27 02:39:43 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "scene.h"
# include "ray.h"
# include "camera.h"
# include <stddef.h>

typedef struct	s_trace
{
	t_ray		*ray;
	int			color;
	size_t		count;
	t_hit		*hits;
}				t_trace;

typedef struct	s_engine t_engine;

typedef struct	s_runner_param
{
	t_trace		*trace;
	t_engine	*engine;
	int			thread_index;
}				t_runner_param;

void			raytrace_frame(t_engine *engine);

t_trace			*init_trace(void);
t_trace			**init_traces(int thread_count);
void			free_trace(t_trace *trace);
void			free_traces(t_trace **traces, int index);

#endif
