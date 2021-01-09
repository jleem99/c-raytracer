/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:57:58 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 13:57:49 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

t_scene			make_scene(void)
{
	t_scene		ret;

	ret.objects = ft_make_array(0);
	return (ret);
}

void			free_scene(t_scene *scene)
{
	ft_free_array(scene->objects);
}
