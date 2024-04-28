/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:09:06 by egervais          #+#    #+#             */
/*   Updated: 2023/10/17 18:41:22 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_scale(double alpha, t_vec3 a)
{
	return ((t_vec3){alpha * a.x, alpha * a.y, alpha * a.z});
}

t_vec3	vec3_lin_comb(double alpha, t_vec3 a, double beta, t_vec3 b)
{
	return (vec3_add(vec3_scale(alpha, a), vec3_scale(beta, b)));
}

double	vec3_dist(t_vec3 a, t_vec3 b)
{
	return (vec3_length(vec3_sub(a, b)));
}

t_vec3	new_vec3(char **components)
{
	t_vec3	vec3;

	vec3.x = ft_atof(components[0]);
	vec3.y = ft_atof(components[1]);
	vec3.z = ft_atof(components[2]);
	return (vec3);
}

t_color	new_color(char **components)
{
	t_color	color;

	color.r = ft_atof(components[0]) / 255;
	color.g = ft_atof(components[1]) / 255;
	color.b = ft_atof(components[2]) / 255;
	color.a = 0;
	return (color);
}
