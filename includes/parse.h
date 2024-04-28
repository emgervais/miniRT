/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:08:39 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/17 18:46:56 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "miniRT.h"

typedef struct s_parse
{
	char		*file;
	char		*line;
	char		**lines;
	int			nb_obj[6];
	int			nb_line;
	int			fd;
	bool		is_valid;
}				t_parse;

t_parse	*parsing(int argc, char **argv);

// Check utils
bool	check_range(char *str, float min, float max);
bool	check_color(char *color);
bool	check_coordinates(char *elem);
bool	check_normal(char *elem, int lenght);

bool	check_ambient(char **elem, t_parse *parse);
bool	check_camera(char **elem, t_parse *parse);
bool	check_light(char **elem, t_parse *parse);
bool	check_sphere(char **elem, t_parse *parse);
bool	check_cylinder(char **elem, t_parse *parse);
bool	check_plane(char **elem, t_parse *parse);

#endif
