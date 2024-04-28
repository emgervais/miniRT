/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:09 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/16 14:24:56 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_ambient(char **elem, t_parse *parse)
{
	if (parse->nb_obj[0] > 0)
		return (ft_error("Ambient light must be declared only once\n", NULL));
	if (ft_splitlen(elem) != 3)
		return (ft_error("Ambient light must have 3 arguments\n", NULL));
	if (!check_range(elem[1], 0.0, 1.0))
		return (ft_error(ERR_RATIO, ERR_AM));
	if (!check_color(elem[2]))
		return (ft_error(ERR_COLOR, ERR_AM));
	parse->nb_obj[0]++;
	return (true);
}

bool	check_camera(char **elem, t_parse *parse)
{
	if (parse->nb_obj[1] > 0)
		return (ft_error("Camera must be declared only once\n", NULL));
	if (ft_splitlen(elem) != 4)
		return (ft_error("Camera must have 4 arguments\n", NULL));
	if (!check_coordinates(elem[1]))
		return (ft_error(ERR_VEC3, ERR_CA));
	if (!check_normal(elem[2], 0))
		return (ft_error(ERR_NORMAL, ERR_CA));
	if (!check_range(elem[3], 0.0, 180.0))
		return (ft_error("Camera FOV must be between 0 and 180\n", NULL));
	parse->nb_obj[1]++;
	return (true);
}

bool	check_light(char **elem, t_parse *parse)
{
	if (parse->nb_obj[2] > 0)
		return (ft_error("Light must be declared only once\n", NULL));
	if (ft_splitlen(elem) != 4)
		return (ft_error("Light must have 4 arguments\n", NULL));
	if (!check_coordinates(elem[1]))
		return (ft_error(ERR_VEC3, ERR_LI));
	if (!check_range(elem[2], 0.0, 1.0))
		return (ft_error(ERR_RATIO, ERR_LI));
	if (!check_color(elem[3]))
		return (ft_error(ERR_COLOR, ERR_LI));
	parse->nb_obj[2]++;
	return (true);
}

bool	check_sphere(char **elem, t_parse *parse)
{
	if (ft_splitlen(elem) != 4)
		return (ft_error("Sphere must have 4 arguments\n", NULL));
	if (!check_coordinates(elem[1]))
		return (ft_error(ERR_VEC3, ERR_SP));
	if (!ft_isfloat(elem[2]) && !ft_isint(elem[2]) && ft_atof(elem[2]) <= 0)
		return (ft_error(ERR_LENGTH, ERR_SP));
	if (!check_color(elem[3]))
		return (ft_error(ERR_COLOR, ERR_SP));
	parse->nb_obj[3]++;
	return (true);
}

bool	check_cylinder(char **elem, t_parse *parse)
{
	if (ft_splitlen(elem) != 6)
		return (ft_error("Cylinder must have 6 arguments\n", NULL));
	if (!check_coordinates(elem[1]))
		return (ft_error(ERR_VEC3, ERR_CY));
	if (!check_normal(elem[2], 0))
		return (ft_error(ERR_NORMAL, ERR_CY));
	if (!ft_isfloat(elem[3]) && !ft_isint(elem[3]) && ft_atof(elem[3]) <= 0)
		return (ft_error(ERR_LENGTH, ERR_CY));
	if (!ft_isfloat(elem[4]) && !ft_isint(elem[4]) && ft_atof(elem[4]) <= 0)
		return (ft_error(ERR_LENGTH, ERR_CY));
	if (!check_color(elem[5]))
		return (ft_error(ERR_COLOR, ERR_CY));
	parse->nb_obj[5]++;
	return (true);
}
