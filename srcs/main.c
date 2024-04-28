/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:40:31 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 14:11:19 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = init_scene(argc, argv);
	if (!scene)
		return (1);
	mlx_image_to_window(scene->mlx, scene->img, 0, 0);
	render(scene);
	mlx_resize_hook(scene->mlx, reseize, scene);
	mlx_key_hook(scene->mlx, move, scene);
	mlx_mouse_hook(scene->mlx, select_objs, scene);
	mlx_loop(scene->mlx);
	free_scene(scene);
	return (0);
}
