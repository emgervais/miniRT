/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:52:46 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 15:22:22 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	*render_thread(void *arg)
{
	t_thread	*data;
	int			max_v;
	int			u;
	int			v;
	t_color		color;

	data = (t_thread *)arg;
	v = data->thread_id * (data->scene->mlx->height / THREADS);
	max_v = (data->thread_id + 1) * (data->scene->mlx->height / THREADS);
	if (data->thread_id == THREADS - 1)
		max_v = data->scene->mlx->height;
	while (v < max_v)
	{
		u = 0;
		while (u < data->scene->mlx->width)
		{
			color = (t_color){0.1, 0.1, 0.1, 1};
			draw_pixel(data->scene, u, v, &color);
			mlx_put_pixel(data->scene->img, u, v, rgba_to_int(&color));
			u++;
		}
		v++;
	}
	return (NULL);
}

void	create_thread(t_scene *scene)
{
	int			i;
	pthread_t	threads[THREADS];
	t_thread	data[THREADS];

	i = 0;
	while (i < THREADS)
	{
		data[i].scene = scene;
		data[i].thread_id = i;
		pthread_create(&threads[i], NULL, render_thread, &data[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	single_thread(t_scene *scene)
{
	int			u;
	int			v;
	t_color		color;

	v = 0;
	while (v < scene->mlx->height)
	{
		u = 0;
		while (u < scene->mlx->width)
		{
			color = (t_color){0.1, 0.1, 0.1, 1};
			draw_pixel(scene, u, v, &color);
			mlx_put_pixel(scene->img, u, v, rgba_to_int(&color));
			u++;
		}
		v++;
	}
}

void	render(t_scene *scene)
{
	if (THREADS == 1)
		single_thread(scene);
	else
		create_thread(scene);
}
