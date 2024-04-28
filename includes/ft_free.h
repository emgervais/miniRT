/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:44:43 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/17 18:57:46 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include "miniRT.h"

typedef struct s_scene	t_scene;

void	free_parsing(t_parse *parse);
void	*free_objects(t_objects *object);
void	*free_before_init(t_parse *parse, t_objects *object);
void	*free_all(t_parse *parse, t_objects *object);
void	free_scene(t_scene *scene);

#endif