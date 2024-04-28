/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:58:09 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/17 18:09:04 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_mul(t_vec3 u, double t)
{
	t_vec3	w;

	w.x = u.x * t;
	w.y = u.y * t;
	w.z = u.z * t;
	return (w);
}

t_vec3	vec3_div(t_vec3 u, double t)
{
	t_vec3	w;

	w.x = u.x / t;
	w.y = u.y / t;
	w.z = u.z / t;
	return (w);
}

t_vec3	vec3_norm(t_vec3 u)
{
	return (vec3_div(u, vec3_length(u)));
}

int32_t	rgba_to_int(t_color *color)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	r = (int32_t)(color->r * 255.999);
	g = (int32_t)(color->g * 255.999);
	b = (int32_t)(color->b * 255.999);
	a = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

t_vec3	vec3_rotate(t_vec3 dir, double angle)
{
	t_vec3	new_dir;

	new_dir.x = dir.x * cos(angle) - dir.y * sin(angle);
	new_dir.y = dir.x * sin(angle) + dir.y * cos(angle);
	new_dir.z = dir.z;
	return (new_dir);
}
