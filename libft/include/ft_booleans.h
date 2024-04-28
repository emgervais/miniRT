/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_booleans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:01:02 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/03 23:42:21 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEANS_H
# define FT_BOOLEANS_H

# include "libft.h"

/*/////////////////////////////////////////////////////////////////////////////
		BOOLEAN FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isfloat(char *str);
int		ft_isint(char *str);

int		ft_ischarset(char c, char *set);
int		ft_isnotcharset(char c, char *set);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int c);
int		ft_isprime(int nb);

#endif //FT_BOOLEANS_H