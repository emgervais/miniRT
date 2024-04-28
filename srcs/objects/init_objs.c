/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:33:00 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/18 19:04:09 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	fill_objects(t_parse *parse, t_objects *object)
{
	char	**components;
	int		i;

	i = 0;
	while (i < parse->nb_line)
	{
		components = ft_split_set(parse->lines[i], " \t");
		if (!components)
			return (false);
		if (ft_strncmp(parse->lines[i], "sp ", 3) == 0)
			add_sphere(object, components);
		else if (ft_strncmp(parse->lines[i], "pl ", 3) == 0)
			add_plane(object, components);
		else if (ft_strncmp(parse->lines[i], "cy ", 3) == 0)
			add_cylinder(object, components);
		else if (ft_strncmp(parse->lines[i], "C ", 2) == 0)
			object->camera = new_camera(components);
		else if (ft_strncmp(parse->lines[i], "L ", 2) == 0)
			object->light = new_light(components);
		else if (ft_strncmp(parse->lines[i], "A ", 2) == 0)
			object->amblight = new_amblight(components);
		ft_free_split(components);
		i++;
	}
	return (true);
}

static void	fill_null(t_objects *object)
{
	int	i;

	i = 0;
	while (i < object->nb_sphere)
		object->sphere[i++] = NULL;
	i = 0;
	while (i < object->nb_plane)
		object->plane[i++] = NULL;
	i = 0;
	while (i < object->nb_cylinder)
		object->cylinder[i++] = NULL;
}

static t_objects	*init_object(t_parse *parse)
{
	t_objects	*object;

	object = malloc(sizeof(t_objects));
	if (!object)
		return (NULL);
	object->nb_sphere = parse->nb_obj[3];
	object->nb_plane = parse->nb_obj[4];
	object->nb_cylinder = parse->nb_obj[5];
	object->sphere = NULL;
	object->plane = NULL;
	object->cylinder = NULL;
	object->amblight = NULL;
	object->light = NULL;
	object->camera = NULL;
	return (object);
}

static bool	check_objects(t_objects *object)
{
	int	i;

	i = 0;
	if (!object->sphere || !object->plane || !object->cylinder)
		return (false);
	while (i < object->nb_sphere)
		if (!object->sphere[i++])
			return (false);
	i = 0;
	while (i < object->nb_plane)
		if (!object->plane[i++])
			return (false);
	i = 0;
	while (i < object->nb_cylinder)
		if (!object->cylinder[i++])
			return (false);
	if (!object->amblight || !object->light || !object->camera)
		return (false);
	return (true);
}

t_objects	*new_objects(t_parse *parse)
{
	t_objects	*object;

	object = init_object(parse);
	if (!object)
		return (NULL);
	object->sphere = malloc(sizeof(t_sphere *) * (object->nb_sphere));
	if (!object->sphere)
		return (free_before_init(parse, object));
	object->plane = malloc(sizeof(t_plane *) * (object->nb_plane));
	if (!object->plane)
		return (free_before_init(parse, object));
	object->cylinder = malloc(sizeof(t_cylinder *) * (object->nb_cylinder));
	if (!object->cylinder)
		return (free_before_init(parse, object));
	fill_null(object);
	if (!fill_objects(parse, object) || !check_objects(object))
		return (free_all(parse, object));
	free_parsing(parse);
	return (object);
}
