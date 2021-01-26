/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:21:56 by jleem             #+#    #+#             */
/*   Updated: 2021/01/26 22:01:02 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "object.h"
# include "trace.h"
# include "hit.h"

t_hit			get_ray_intersection_from_object(t_ray *ray, t_object *obj);
t_hit			get_ray_intersection_from_scene(t_trace *trace, t_scene *scene);

#endif
