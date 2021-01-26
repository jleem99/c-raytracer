/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:38:26 by jleem             #+#    #+#             */
/*   Updated: 2021/01/27 00:28:59 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdlib.h>

t_engine		*init_engine(int thread_count)
{
	t_engine	*engine;

	if (!(engine = malloc(sizeof(t_engine))) ||
		!(engine->scene = make_scene()) ||
		!(engine->traces = init_traces(thread_count)))
	{
		free_engine(engine);
		return (NULL);
	}
	engine->thread_count = thread_count;
	return (engine);
}

void			free_engine(t_engine *engine)
{
	if (engine)
	{
		if (engine->scene)
		{
			if (engine->traces)
				free_traces(engine->traces, engine->thread_count - 1);
			free_scene(engine->scene);
		}
		free(engine);
	}
}
