/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:27:35 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/17 18:54:45 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_H
# define COMPONENT_H

# include "miniRT.h"

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_color;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	pos;
	t_vec3	dir;
}	t_ray;

t_vec3	vec3_add(t_vec3 u, t_vec3 v);
t_vec3	vec3_sub(t_vec3 u, t_vec3 v);
double	vec3_dot(t_vec3 u, t_vec3 v);
double	vec3_length(t_vec3 u);
t_vec3	vec3_cross(t_vec3 u, t_vec3 v);
t_vec3	vec3_mul(t_vec3 u, double t);
t_vec3	vec3_div(t_vec3 u, double t);
t_vec3	vec3_norm(t_vec3 u);
t_vec3	vec3_rotate(t_vec3 dir, double angle);
t_vec3	vec3_reflect(t_vec3 v, t_vec3 n);
int32_t	rgba_to_int(t_color *color);
void	calculateCylinderNormal(t_vec3 v, t_vec3 *n, t_vec3 cylco);
t_vec3	vec3_scale(double alpha, t_vec3 a);
t_vec3	vec3_lin_comb(double alpha, t_vec3 a, double beta, t_vec3 b);
double	vec3_dist(t_vec3 a, t_vec3 b);

t_vec3	_vec3(double x, double y, double z);
t_color	_color(float r, float g, float b, float a);
t_ray	_ray(t_vec3 pos, t_vec3 dir);

#endif