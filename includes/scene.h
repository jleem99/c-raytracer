/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:53:29 by jleem             #+#    #+#             */
/*   Updated: 2021/01/08 10:03:58 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stddef.h>
# include "object.h"

typedef struct	s_scene
{
	t_object	**objects;
	size_t		objects_num;
}				t_scene;

t_scene			make_scene(void);
int				scene_push_object(t_scene *scene, t_object *obj);
void			free_scene(t_scene *scene);

#endif
