/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:18:30 by egervais          #+#    #+#             */
/*   Updated: 2023/10/17 18:53:01 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# include "miniRT.h"

t_vec3	rotate_y(t_vec3 vec, double angle);
void	rotate_camera(t_camera *camera, double angle);
void	new_dir(t_vec3 *co);
void	mod_sphere(t_sphere *sphere, t_mod act);
void	mod_plane(t_plane *plane, t_mod act);
void	mod_cylinder(t_cylinder *cylinder, t_mod act);
void	mod_light(t_light *light, t_mod act, bool l, t_amblight *al);
void	modify(t_objects *objects, void *hit, t_mod act, int i);
void	get_objs(t_scene *scene, t_hit_info *hit_info, int pos[2]);
void	select_objs(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param);
#endif