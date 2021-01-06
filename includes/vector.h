/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:27:46 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 23:40:56 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include "math.h"

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

t_vec3			vec3_add(t_vec3 u, t_vec3 v);
t_vec3			vec3_subtract(t_vec3 u, t_vec3 v);
float			vec3_dot_product(t_vec3 u, t_vec3 v);
t_vec3			vec3_cross_product(t_vec3 u, t_vec3 v);
t_vec3			vec3_normalize(t_vec3 v);

t_vec3			make_vec3(float x, float y, float z);
t_vec3			vec3_multiply(t_vec3 v, float k);
float			vec3_square(t_vec3 v);

#endif
