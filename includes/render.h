/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:50:04 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 15:17:43 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "miniRT.h"

typedef struct s_scene	t_scene;

typedef struct s_equation
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
}				t_equation;

typedef enum s_mod
{
	ADD,
	SUB,
	RIGHT,
	LEFT,
	UP,
	DOWN,
	FRONT,
	BACK,
	ROT,
}	t_mod;

void		draw_pixel(t_scene *scene, int x, int y, t_color *color);
t_ray		get_ray(t_camera *camera, int u, int v, mlx_t *mlx);
void		hit_sphere(t_sphere *sphere, t_ray ray, t_hit_info *hit_info);
void		hit_plane(t_plane *plane, t_ray ray, t_hit_info *hit_info);
void		hit_cylinder(t_cylinder *cylinder, t_ray ray, t_hit_info *hit_info);
void		hit_light(t_light *light, t_ray ray, t_hit_info *hit_info,
				t_color *color);
void		hit(t_objects *objects, t_ray ray, t_hit_info *hit_info);
void		normal_of_tube(t_cylinder *cylinder, t_hit_info *hit_info);
void		intersect_tube_quadratic(t_cylinder *cylinder,
				t_ray *ray, double abc[3]);
void		set_values(t_hit_info *hit_info, double t,
				t_ray *ray, t_cylinder *cylinder);

#endif