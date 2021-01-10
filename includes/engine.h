/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:36:06 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 17:57:00 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "scene.h"
# include "trace.h"

typedef struct	s_engine
{
	t_scene		*scene;
	t_trace		*trace;
}				t_engine;

t_engine		*init_engine(void);
void			free_engine(t_engine *engine);

#endif
