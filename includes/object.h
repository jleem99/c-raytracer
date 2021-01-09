/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:49:20 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 19:05:35 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef enum		e_object_type
{
	obj_type_box,
	obj_type_sphere
}					t_object_type;

typedef struct		s_object
{
	t_object_type	type;
	t_vec3			location;
	t_vec3			forward;
	float			radius;
	int				color;
}					t_object;

t_object			*make_sphere(t_vec3 location, float radius, int color);

#endif
