/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:57:58 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 19:02:39 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

t_scene			*make_scene(void)
{
	t_scene		*scene;

	if (!(scene = malloc(sizeof(t_scene))))
		return (NULL);
	scene->objects = ft_make_array(0);
	return (scene);
}

void			free_scene(t_scene *scene)
{
	ft_free_array_data(scene->objects);
	ft_free_array(scene->objects);
	free(scene);
}
