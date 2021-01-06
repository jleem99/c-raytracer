/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:21:56 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 10:30:14 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "object.h"
# include "scene.h"
# include "hit.h"
# include "ray.h"

t_hit			get_ray_intersection_from_object(t_ray *ray, t_object *obj);
t_hit			get_ray_intersection_from_scene(t_ray *ray, t_scene *scene);

#endif
