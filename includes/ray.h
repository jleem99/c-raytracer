/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:27:20 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 02:47:02 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "hit.h"

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		forward;
}				t_ray;

t_vec3			ray_at(t_ray *ray, float t);

#endif
