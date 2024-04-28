/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:13:42 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/18 19:26:32 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	add_sphere(t_objects *object, char **components)
{
	int	i;

	i = 0;
	while (object->sphere[i])
		i++;
	object->sphere[i] = new_sphere(components);
}

void	add_plane(t_objects *object, char **components)
{
	int	i;

	i = 0;
	while (object->plane[i])
		i++;
	object->plane[i] = new_plane(components);
}

void	add_disk(t_cylinder *cylinder)
{
	t_vec3	origin;

	origin = vec3_add(cylinder->pos,
			vec3_mul(cylinder->dir, cylinder->height / 2));
	cylinder->disk[0].pos = origin;
	cylinder->disk[0].dir = cylinder->dir;
	cylinder->disk[0].radius = cylinder->radius;
	cylinder->disk[0].color = cylinder->color;
	origin = vec3_sub(cylinder->pos,
			vec3_mul(cylinder->dir, cylinder->height / 2));
	cylinder->disk[1].pos = origin;
	cylinder->disk[1].dir = vec3_mul(cylinder->dir, -1);
	cylinder->disk[1].radius = cylinder->radius;
	cylinder->disk[1].color = cylinder->color;
}

void	add_cylinder(t_objects *object, char **components)
{
	int	i;

	i = 0;
	while (object->cylinder[i])
		i++;
	object->cylinder[i] = new_cylinder(components);
}

t_sphere	*new_sphere(char **components)
{
	t_sphere	*sphere;
	char		**split;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	split = ft_split(components[1], ',');
	if (!split)
		return (free(sphere), NULL);
	sphere->pos = new_vec3(split);
	ft_free_split(split);
	sphere->radius = ft_atof(components[2]) / 2;
	split = ft_split(components[3], ',');
	if (!split)
		return (free(sphere), NULL);
	sphere->color = new_color(split);
	ft_free_split(split);
	return (sphere);
}
