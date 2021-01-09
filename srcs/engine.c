/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:38:26 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 03:04:53 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdlib.h>

t_engine		*init_engine(void *mlx, void *mlx_win)
{
	t_engine	*engine;

	if (!(engine = malloc(sizeof(t_engine))) ||
		!(engine->scene = make_scene()) ||
		!(engine->trace = malloc(sizeof(t_trace))) ||
		!(engine->trace->ray = malloc(sizeof(t_ray))))
	{
		free_engine(engine);
		return (NULL);
	}
	engine->mlx = mlx;
	engine->mlx_win = mlx_win;
	engine->trace->scene = engine->scene;
	return (engine);
}

void			free_engine(t_engine *engine)
{
	if (engine)
	{
		if (engine->scene)
		{
			if (engine->trace)
			{
				if (engine->trace->ray)
					free(engine->trace->ray);
				free(engine->trace);
			}
			free_scene(engine->scene);
		}
	free(engine);
	}
}
