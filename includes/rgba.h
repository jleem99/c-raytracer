/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 01:18:22 by jleem             #+#    #+#             */
/*   Updated: 2021/01/24 20:24:42 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBA_H
# define RGBA_H

int		rgba(int r, int g, int b, int a);
int		rgba_r(int rgba);
int		rgba_g(int rgba);
int		rgba_b(int rgba);
int		rgba_a(int rgba);

int		rgba_blend(int rgba1, int rgba2, float alpha);
int		rgba_multiply(int rgba_, float k);

#endif
