/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:53:29 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 23:51:36 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include "camera.h"
# include "libft_bonus.h"

typedef struct	s_scene
{
	t_array		*objects;
	t_array		*cameras;
}				t_scene;

t_scene			*make_scene(void);
void			free_scene(t_scene *scene);
t_object		*scene_get_object(t_scene *scene, size_t index);
t_camera		*scene_get_camera(t_scene *scene, size_t index);

#endif
