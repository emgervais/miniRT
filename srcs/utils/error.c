/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:42:10 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/17 18:11:51 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	ft_error(char *str, char *obj)
{
	ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
	if (obj)
	{
		ft_putstr_fd(obj, 2);
		ft_putstr_fd(" : ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (false);
}

void	*ft_error_free(t_parse *ptr, char *str)
{
	if (str)
		ft_error(str, NULL);
	free_parsing(ptr);
	return (NULL);
}
