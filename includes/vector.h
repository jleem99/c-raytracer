/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:27:46 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 15:48:35 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "math.h"

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

t_vector		add_vector(t_vector vect1, t_vector vect2);
t_vector		subtract_vector(t_vector vect1, t_vector vect2);
float			dot_product(t_vector u, t_vector v);
t_vector		cross_product(t_vector u, t_vector v);
t_vector		normalize_vector(t_vector vect);

t_vector		make_vector(float x, float y, float z);
t_vector		multiply_vector(t_vector vect, float k);
float			square_vector(t_vector vect);

#endif
