/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:49:33 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/19 12:04:16 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "miniRT.h"

# define ERR_CY "Cylinder"
# define ERR_SP "Sphere"
# define ERR_PL "Plane"
# define ERR_AM "Ambient light"
# define ERR_CA "Camera"
# define ERR_LI "Light"
# define ERR_COLOR "Need a color. Format : \
	R,G,B (each value must be an integer between 0 and 255)\n"
# define ERR_VEC3 "Need a vector. Format : X,Y,Z (each value must be a float)\n"
# define ERR_RATIO "Need a ratio between 0 and 1 (float)\n"
# define ERR_FILE "Usage : ./miniRT <file.rt>\n"
# define ERR_EXT "Wrong extension of file, need .rt\n"
# define ERR_FOV "Need a fov between 0 and 180 (integer)\n"
# define ERR_NORMAL "Need a normal vector, the length of the vector must be 1\n"
# define ERR_LENGTH "Diameter, height and fov must be greater than 0\n"
# define ERR_ID "Wrong ID\n"
# define ERR_MALLOC "Malloc error\n"
# define ERR_OPEN "Unable to open file\n"
# define ERR_READ "Unable to read file\n"
# define ERR_MLX "Unable to initialize MLX\n"

# define REQUIRED "List of required elements in file.rt :\n\
    - (only 1) Ambient light : (ID = A, color = RGB, ratio = float [0, 1])\n\
    - (only 1) Camera : (ID = C, position = XYZ, orientation = XYZ, fov = int [0, 180])\n\
    - (only 1) Light : (ID = L, position = XYZ, ratio = float [0, 1], color = RGB)\n\
    - (optional) Sphere : (ID = sp, position = XYZ, diameter = float, color = RGB)\n\
    - (optional) Plane : (ID = pl, position = XYZ, orientation = XYZ, color = RGB)\n\
    - (optional) Cylinder : (ID = cy, position = XYZ, orientation = XYZ, diameter = float, height = float, color = RGB)\n\n\
    * Orientation is the direction of the normal vector, the length of the vector must be 1\n\
    * Diameter, height and fov must be greater than 0\n\
    * Color is RGB, each value must be an integer between 0 and 255\n\n\
Example :\n\
    A 0.2    255,255,255\n\
    C -50,0,20    0,0,0    70\n\
    L -40,0,30    0.7    255,255,255\n\
    pl 0,0,0    0,1.0,0    255,0,225\n\
    sp 0,0,20    20    255,0,0\n\
    cy 50.0,0.0,20.6    0,0,1.0    14.2 21.42    10,0,255\n"

bool	ft_error(char *str, char *obj);
void	*ft_error_free(t_parse *ptr, char *str);

#endif