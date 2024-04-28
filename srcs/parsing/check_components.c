/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:43:46 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/18 19:07:17 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_range(char *str, float min, float max)
{
	float	nb;

	nb = ft_atof(str);
	if (nb < min || nb > max)
		return (false);
	return (true);
}

bool	check_color(char *color)
{
	char	**rgb;
	int		i;

	rgb = ft_split(color, ',');
	if (ft_count_specific_char(color, ',') != 2)
		return (ft_free_split(rgb), false);
	i = 0;
	while (rgb[i])
	{
		if (!ft_isint(rgb[i]))
			break ;
		if (!check_range(rgb[i], 0, 255))
			break ;
		i++;
	}
	ft_free_split(rgb);
	if (i != 3)
		return (false);
	return (true);
}

bool	check_coordinates(char *elem)
{
	char	**coord;
	int		i;

	coord = ft_split(elem, ',');
	if (ft_count_specific_char(elem, ',') != 2)
	{
		ft_free_split(coord);
		return (false);
	}
	i = 0;
	while (coord[i])
	{
		if (!ft_isfloat(coord[i]) && !ft_isint(coord[i]))
			break ;
		i++;
	}
	ft_free_split(coord);
	if (i != 3)
		return (false);
	return (true);
}

bool	check_normal(char *elem, int lenght)
{
	char	**coord;
	int		i;

	coord = ft_split(elem, ',');
	if (ft_count_specific_char(elem, ',') != 2)
	{
		ft_free_split(coord);
		return (false);
	}
	i = 0;
	while (coord[i])
	{
		if (!ft_isfloat(coord[i]) && !ft_isint(coord[i]))
			break ;
		lenght += ft_atof(coord[i]) * ft_atof(coord[i]);
		i++;
	}
	ft_free_split(coord);
	if (i != 3)
		return (false);
	lenght = ft_sqrt(lenght);
	if (lenght < 0.99 || lenght > 1.01)
		return (false);
	return (true);
}

bool	check_plane(char **elem, t_parse *parse)
{
	if (ft_splitlen(elem) != 4)
		return (ft_error("Error: Plane must have 4 arguments\n", NULL));
	if (!check_coordinates(elem[1]))
		return (ft_error(ERR_VEC3, ERR_PL));
	if (!check_normal(elem[2], 0))
		return (ft_error(ERR_NORMAL, ERR_PL));
	if (!check_color(elem[3]))
		return (ft_error(ERR_COLOR, ERR_PL));
	parse->nb_obj[4]++;
	return (true);
}
