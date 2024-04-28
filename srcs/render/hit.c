/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:01:30 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 15:19:38 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_values(t_hit_info *hit_info, double t,
		t_ray *ray, t_cylinder *cylinder)
{
	hit_info->dist = t;
	hit_info->collided = true;
	hit_info->hit.pos = vec3_add(ray->pos, vec3_mul(ray->dir, hit_info->dist));
	normal_of_tube(cylinder, hit_info);
	hit_info->hit.dir = vec3_norm(hit_info->hit.dir);
	hit_info->color = cylinder->color;
	hit_info->obj_hit = (void *)cylinder;
	hit_info->type = 0;
}

void	hit_sphere(t_sphere *sphere, t_ray ray, t_hit_info *hit_info)
{
	t_equation	equation;
	t_vec3		oc;

	oc = vec3_sub(ray.pos, sphere->pos);
	equation.a = vec3_dot(ray.dir, ray.dir);
	equation.b = 2 * vec3_dot(ray.dir, oc);
	equation.c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	equation.delta = equation.b * equation.b - 4 * equation.a * equation.c;
	if (equation.delta < 0)
		return ;
	equation.t1 = (-equation.b + sqrt(equation.delta)) / (2 * equation.a);
	equation.t2 = (-equation.b - sqrt(equation.delta)) / (2 * equation.a);
	if (equation.t1 < 0 && equation.t2 < 0)
		return ;
	if (hit_info->dist < equation.t1 && hit_info->dist < equation.t2)
		return ;
	hit_info->dist = get_min(equation.t1, equation.t2);
	hit_info->collided = true;
	hit_info->hit.pos = vec3_add(ray.pos, vec3_mul(ray.dir, hit_info->dist));
	hit_info->hit.dir = vec3_norm(vec3_sub(hit_info->hit.pos, sphere->pos));
	hit_info->color = sphere->color;
	hit_info->obj_hit = (void *)sphere;
	hit_info->type = 2;
}

void	hit_plane(t_plane *plane, t_ray ray, t_hit_info *hit_info)
{
	double	t;
	double	denom;
	t_vec3	oc;

	denom = vec3_dot(plane->dir, ray.dir);
	if (fabs(denom) > 1e-6)
	{
		oc = vec3_sub(plane->pos, ray.pos);
		t = vec3_dot(oc, plane->dir) / denom;
		if (t < 0 || hit_info->dist < t)
			return ;
		hit_info->dist = t;
		hit_info->collided = true;
		hit_info->hit.pos = vec3_add(ray.pos,
				vec3_mul(ray.dir, hit_info->dist));
		hit_info->hit.dir = plane->dir;
		if (vec3_dot(plane->dir, ray.dir) > 0)
			hit_info->hit.dir = vec3_mul(hit_info->hit.dir, -1);
		hit_info->color = plane->color;
		hit_info->obj_hit = (void *)plane;
		hit_info->type = 1;
	}
}

void	hit_light(t_light *light, t_ray ray, t_hit_info *hit_info,
		t_color *color)
{
	t_sphere	sphere;

	hit_info->collided = false;
	sphere.pos = light->pos;
	sphere.radius = 0.1;
	sphere.color = light->color;
	hit_sphere(&sphere, ray, hit_info);
	if (hit_info->collided)
	{
		color->r = 1;
		color->g = 1;
		color->b = 1;
	}
}

void	hit(t_objects *objects, t_ray ray, t_hit_info *hit_info)
{
	int	i;

	i = 0;
	while (i < objects->nb_sphere)
	{
		hit_sphere(objects->sphere[i], ray, hit_info);
		i++;
	}
	i = 0;
	while (i < objects->nb_plane)
	{
		hit_plane(objects->plane[i], ray, hit_info);
		i++;
	}
	i = 0;
	while (i < objects->nb_cylinder)
	{
		hit_cylinder(objects->cylinder[i], ray, hit_info);
		i++;
	}
}
