/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:10:47 by egervais          #+#    #+#             */
/*   Updated: 2023/10/17 18:41:26 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

t_vec3	_vec3(double x, double y, double z)
{
	t_vec3	w;

	w.x = x;
	w.y = y;
	w.z = z;
	return (w);
}

t_color	_color(float r, float g, float b, float a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_ray	_ray(t_vec3 pos, t_vec3 dir)
{
	t_ray	ray;

	ray.pos = pos;
	ray.dir = dir;
	return (ray);
}

t_vec3	vec3_reflect(t_vec3 v, t_vec3 n)
{
	return (vec3_sub(v, vec3_mul(n, 2 * vec3_dot(v, n))));
}
