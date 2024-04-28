/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:40:54 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 15:25:53 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <pthread.h>
# include "../libft/include/libft.h"
# include "../mlx/include/MLX42/MLX42.h"
# include "parse.h"
# include "component.h"
# include "error.h"
# include "object.h"
# include "ft_free.h"
# include "render.h"
# include "macro.h"

typedef struct s_scene	t_scene;

# define WIDTH 1920
# define HEIGHT 1080
# ifndef THREADS
#  define THREADS 12
# endif

struct s_scene
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_objects	*objs;
	void		*selected;
};

typedef struct s_thread
{
	t_scene		*scene;
	int			thread_id;
}	t_thread;

t_scene	*init_scene(int argc, char **argv);
void	move(mlx_key_data_t key_data, void *param);
void	reseize(int32_t width, int32_t height, void *param);
void	create_thread(t_scene *scene);
void	single_thread(t_scene *scene);
void	render(t_scene *scene);

#endif