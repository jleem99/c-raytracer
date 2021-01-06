/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:25:09 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 15:54:29 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "object.h"
# include "vector.h"

typedef struct	s_hit
{
	t_object	*object;
	t_vector	location;
	float		distance;
}				t_hit;

#endif
