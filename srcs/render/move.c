/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:54:32 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 15:29:36 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move3(keys_t key, t_camera *camera)
{
	if (key == MLX_KEY_RIGHT)
		rotate_camera(camera, 0.1);
	else if (key == MLX_KEY_LEFT)
		rotate_camera(camera, -0.1);
	else if (key == MLX_KEY_DOWN)
		camera->pos = vec3_add(camera->pos, vec3_mul(camera->up, 1));
	else if (key == MLX_KEY_UP)
		camera->pos = vec3_sub(camera->pos, vec3_mul(camera->up, 1));
	else if (key == MLX_KEY_S)
		camera->pos = vec3_sub(camera->pos, vec3_mul(camera->dir, 1));
	else if (key == MLX_KEY_A)
		camera->pos = vec3_sub(camera->pos, vec3_mul(camera->right, 1));
	else
		return (1);
	return (0);
}

int	move2(keys_t key, t_camera *camera, t_scene *scene)
{
	if (key == MLX_KEY_W)
		camera->pos = vec3_add(camera->pos, vec3_mul(camera->dir, 1));
	else if (key == MLX_KEY_D)
		camera->pos = vec3_add(camera->pos, vec3_mul(camera->right, 1));
	else if (key == MLX_KEY_KP_ADD && scene->selected)
		modify(scene->objs, scene->selected, ADD, 0);
	else if (key == MLX_KEY_KP_SUBTRACT && scene->selected)
		modify(scene->objs, scene->selected, SUB, 0);
	else if (key == MLX_KEY_R && scene->selected)
		modify(scene->objs, scene->selected, ROT, 0);
	else if (key == MLX_KEY_KP_6 && scene->selected)
		modify(scene->objs, scene->selected, RIGHT, 0);
	else if (key == MLX_KEY_KP_4 && scene->selected)
		modify(scene->objs, scene->selected, LEFT, 0);
	else if (key == MLX_KEY_KP_8 && scene->selected)
		modify(scene->objs, scene->selected, DOWN, 0);
	else if (key == MLX_KEY_KP_5 && scene->selected)
		modify(scene->objs, scene->selected, UP, 0);
	else if (key == MLX_KEY_KP_7 && scene->selected)
		modify(scene->objs, scene->selected, FRONT, 0);
	else if (key == MLX_KEY_KP_9 && scene->selected)
		modify(scene->objs, scene->selected, BACK, 0);
	else
		return (move3(key, camera));
	return (0);
}

void	move(mlx_key_data_t key_data, void *param)
{
	t_scene		*scene;
	t_camera	*camera;
	bool		changed;

	changed = true;
	scene = (t_scene *)param;
	camera = scene->objs->camera;
	if (key_data.key == MLX_KEY_ESCAPE)
		free_scene(scene);
	else if (key_data.key == MLX_KEY_L)
		scene->selected = (void *)scene->objs->light;
	else if (key_data.key == MLX_KEY_O)
		scene->selected = (void *)scene->objs->amblight;
	else
		if (move2(key_data.key, camera, scene))
			changed = false;
	if (changed)
		render(scene);
}

void	reseize(int32_t width, int32_t height, void *param)
{
	t_scene		*scene;
	t_camera	*camera;

	scene = (t_scene *)param;
	camera = scene->objs->camera;
	camera->aspect_ratio = width / height;
	camera->half_h = camera->half_w * height / width;
	scene->mlx->width = width;
	scene->mlx->height = height;
	mlx_resize_image(scene->img, width, height);
	render(scene);
}
