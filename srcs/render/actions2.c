/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:17:10 by egervais          #+#    #+#             */
/*   Updated: 2023/10/19 15:19:13 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	rotate_y(t_vec3 vec, double angle)
{
	double	cos_a;
	double	sin_a;
	t_vec3	result;

	cos_a = cos(angle);
	sin_a = sin(angle);
	result.x = cos_a * vec.x - sin_a * vec.z;
	result.y = vec.y;
	result.z = sin_a * vec.x + cos_a * vec.z;
	return (result);
}

void	rotate_camera(t_camera *camera, double angle)
{
	camera->dir = rotate_y(camera->dir, angle);
	camera->right = vec3_cross(camera->dir, (t_vec3){0, 1, 0});
	camera->up = vec3_cross(camera->right, camera->dir);
	camera->dir = vec3_norm(camera->dir);
	camera->right = vec3_norm(camera->right);
	camera->up = vec3_norm(camera->up);
}

void	new_dir(t_vec3 *co)
{
	if (co->x)
	{
		co->x = 0;
		co->y = 1;
	}
	else if (co->y)
	{
		co->y = 0;
		co->z = 1;
	}
	else
	{
		co->z = 0;
		co->x = 1;
	}
}

void	get_objs(t_scene *scene, t_hit_info *hit_info, int pos[2])
{
	t_ray		ray;

	hit_info->collided = false;
	hit_info->dist = INFINITY;
	mlx_get_mouse_pos(scene->mlx, &pos[0], &pos[1]);
	ray = get_ray(scene->objs->camera, pos[0], pos[1], scene->mlx);
	hit(scene->objs, ray, hit_info);
}

void	select_objs(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param)
{
	t_scene		*scene;
	t_hit_info	hit_info;
	int			pos[2];

	scene = (t_scene *)param;
	mods = 0;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == 0)
	{
		get_objs(scene, &hit_info, pos);
		if (hit_info.collided)
			scene->selected = (void *)hit_info.obj_hit;
	}
	else if (button == MLX_MOUSE_BUTTON_RIGHT && action == 0)
		scene->selected = NULL;
	render(scene);
}
