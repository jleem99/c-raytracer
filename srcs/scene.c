/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:57:58 by jleem             #+#    #+#             */
/*   Updated: 2021/01/23 20:59:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"
#include <stdlib.h>

t_scene			*make_scene(void)
{
	t_scene		*scene;

	if (!(scene = malloc(sizeof(t_scene))) ||
		!(scene->objects = ft_make_array(0)) ||
		!(scene->cameras = ft_make_array(0)))
	{
		free_scene(scene);
		return (NULL);
	}
	return (scene);
}

void			free_scene(t_scene *scene)
{
	if (scene)
	{
		if (scene->objects)
		{
			if (scene->cameras)
			{
				ft_free_array_data(scene->cameras);
				ft_free_array(scene->cameras);
			}
			ft_free_array_data(scene->objects);
			ft_free_array(scene->objects);
		}
		free(scene);
	}
}

t_object		*scene_get_object(t_scene *scene, size_t index)
{
	return (scene->objects->data[index]);
}

t_camera		*scene_get_camera(t_scene *scene, size_t index)
{
	return (scene->cameras->data[index]);
}
