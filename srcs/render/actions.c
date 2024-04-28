/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:17:10 by egervais          #+#    #+#             */
/*   Updated: 2023/10/19 15:30:39 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mod_sphere(t_sphere *sphere, t_mod act)
{
	if (act == ADD)
		sphere->radius += 0.1;
	else if (act == SUB && sphere->radius > 0.1)
		sphere->radius -= 0.1;
	else if (act == RIGHT)
		sphere->pos.x += 0.1;
	else if (act == LEFT)
		sphere->pos.x -= 0.1;
	else if (act == UP)
		sphere->pos.y += 0.1;
	else if (act == DOWN)
		sphere->pos.y -= 0.1;
	else if (act == BACK)
		sphere->pos.z -= 0.1;
	else if (act == FRONT)
		sphere->pos.z += 0.1;
	else
		return ;
}

void	mod_plane(t_plane *plane, t_mod act)
{
	if (act == ROT)
		new_dir(&plane->dir);
	else if (act == RIGHT)
		plane->pos.x += 0.1;
	else if (act == LEFT)
		plane->pos.x -= 0.1;
	else if (act == UP)
		plane->pos.y += 0.1;
	else if (act == DOWN)
		plane->pos.y -= 0.1;
	else if (act == BACK)
		plane->pos.z -= 0.1;
	else if (act == FRONT)
		plane->pos.z += 0.1;
	else
		return ;
}

void	mod_cylinder(t_cylinder *cylinder, t_mod act)
{
	if (act == ROT)
		new_dir(&cylinder->dir);
	else if (act == ADD)
	{
		cylinder->radius += 0.1;
		cylinder->height += 0.1;
	}
	else if (act == SUB && cylinder->radius > 0.2 && cylinder->height > 0.2)
	{
		cylinder->radius -= 0.1;
		cylinder->height -= 0.1;
	}
	else if (act == RIGHT)
		cylinder->pos.x += 0.1;
	else if (act == LEFT)
		cylinder->pos.x -= 0.1;
	else if (act == UP)
		cylinder->pos.y += 0.1;
	else if (act == DOWN)
		cylinder->pos.y -= 0.1;
	else if (act == BACK)
		cylinder->pos.z -= 0.1;
	else
		cylinder->pos.z += 0.1;
	add_disk(cylinder);
}

void	mod_light(t_light *light, t_mod act, bool l, t_amblight *al)
{
	if (act == RIGHT && l != 0)
		light->pos.x += 0.11;
	else if (act == LEFT && l != 0)
		light->pos.x -= 0.11;
	else if (act == FRONT && l != 0)
		light->pos.z += 0.11;
	else if (act == UP && l != 0)
		light->pos.y += 0.11;
	else if (act == DOWN && l != 0)
		light->pos.y -= 0.11;
	else if (act == BACK && l != 0)
		light->pos.z -= 0.11;
	else if (act == ADD && l != 0 && light->ratio + 0.1 <= 1)
		light->ratio += 0.1;
	else if (act == SUB && l != 0 && light->ratio - 0.1 >= 0)
		light->ratio -= 0.1;
	else if (act == ADD && l == 0 && al->ratio + 0.1 <= 1)
		al->ratio += 0.1;
	else if (act == SUB && l == 0 && al->ratio - 0.1 >= 0)
		al->ratio -= 0.1;
	else
		return ;
}

void	modify(t_objects *objects, void *hit, t_mod act, int i)
{
	while (i < objects->nb_plane)
	{
		if ((t_plane *)hit == objects->plane[i])
			mod_plane(objects->plane[i], act);
		i++;
	}
	i = 0;
	while (i < objects->nb_cylinder)
	{
		if ((t_cylinder *)hit == objects->cylinder[i])
			mod_cylinder(objects->cylinder[i], act);
		i++;
	}
	i = 0;
	while (i < objects->nb_sphere)
	{
		if ((t_sphere *)hit == objects->sphere[i])
			mod_sphere(objects->sphere[i], act);
		i++;
	}
	if ((t_light *)hit == objects->light)
		mod_light(objects->light, act, 1, NULL);
	if ((t_amblight *)hit == objects->amblight)
		mod_light(NULL, act, 0, objects->amblight);
}
