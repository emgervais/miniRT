/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:30:00 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 11:28:50 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "miniRT.h"

typedef struct s_sphere
{
	t_vec3			pos;
	double			radius;
	t_color			color;
}				t_sphere;

typedef struct s_plane
{
	t_vec3			pos;
	t_vec3			dir;
	t_color			color;
}				t_plane;

typedef struct s_disk
{
	t_vec3			pos;
	t_vec3			dir;
	double			radius;
	t_color			color;
}				t_disk;

typedef struct s_cylinder
{
	t_disk			disk[2];
	t_vec3			pos;
	t_vec3			dir;
	double			radius;
	double			height;
	t_color			color;
}				t_cylinder;

typedef struct s_amblight
{
	double			ratio;
	t_color			color;
}				t_amblight;

typedef struct s_light
{
	t_vec3			pos;
	double			ratio;
	t_color			color;
}				t_light;

typedef struct s_camera
{
	t_vec3		pos;
	t_vec3		dir;
	t_vec3		up;
	t_vec3		right;
	double		fov;
	double		aspect_ratio;
	double		theta;
	double		half_h;
	double		half_w;
}				t_camera;

typedef struct s_objects
{
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_amblight	*amblight;
	t_light		*light;
	t_camera	*camera;
	int			nb_sphere;
	int			nb_plane;
	int			nb_cylinder;
}				t_objects;

typedef struct s_hit_info
{
	t_ray		hit;
	t_color		color;
	double		dist;
	bool		collided;
	void		*obj_hit;
	int			type;
}				t_hit_info;

typedef struct s_form
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_form;

t_objects	*new_objects(t_parse *parse);

t_sphere	*new_sphere(char **components);
t_plane		*new_plane(char **components);
t_cylinder	*new_cylinder(char **components);
t_amblight	*new_amblight(char **components);
t_light		*new_light(char **components);
t_camera	*new_camera(char **components);

void		add_sphere(t_objects *object, char **components);
void		add_plane(t_objects *object, char **components);
void		add_disk(t_cylinder *cylinder);
void		add_cylinder(t_objects *object, char **components);

t_vec3		new_vec3(char **components);
t_color		new_color(char **components);

#endif
