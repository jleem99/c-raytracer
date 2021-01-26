/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:36:06 by jleem             #+#    #+#             */
/*   Updated: 2021/01/27 00:28:14 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "scene.h"
# include "trace.h"

typedef struct	s_engine
{
	t_scene		*scene;
	t_trace		**traces;
	int			thread_count;
	void		(*put_pixel)(int x, int y, int color);
}				t_engine;

t_engine		*init_engine(int thread_count);
void			free_engine(t_engine *engine);

#endif
