/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:53:29 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 14:11:38 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stddef.h>
# include "object.h"
# include "libft_bonus.h"

typedef struct	s_scene
{
	t_array		*objects;
}				t_scene;

t_scene			make_scene(void);
void			free_scene(t_scene *scene);

#endif
