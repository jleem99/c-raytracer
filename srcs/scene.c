/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:57:58 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 16:27:16 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

t_scene			make_scene(void)
{
	t_scene		ret;

	ret.objects = NULL;
	ret.objects_num = 0;
	return (ret);
}

int				scene_push_object(t_scene *scene, t_object *obj)
{
	t_object	**objects;
	size_t		i;

	if (!(objects = malloc(sizeof(*objects) * (scene->objects_num + 1))))
		return (0);
	i = 0;
	while (i < scene->objects_num)
	{
		objects[i] = scene->objects[i];
		i++;
	}
	objects[i] = obj;
	free(scene->objects);
	scene->objects = objects;
	scene->objects_num++;
	return (1);
}
