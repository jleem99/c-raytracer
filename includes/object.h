/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:49:20 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 23:42:48 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef enum		e_object_type
{
	box,
	sphere
}					t_object_type;

typedef struct		s_object
{
	t_object_type	type;
	t_vec3			location;
	t_vec3			forward;
	float			radius;
	int				color;
}					t_object;

#endif
