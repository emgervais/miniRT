/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:12:47 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/18 19:13:28 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (s[a])
	{
		if (s[a] == (char)c)
			return (a);
		a++;
	}
	if (s[a] == (char)c)
		return (a);
	return (-1);
}

int	ft_int_strchr_set(const char *s, const char *set)
{
	int	a;

	a = 0;
	while (s[a])
	{
		if (ft_strchr(set, s[a]))
			return (a);
		a++;
	}
	if (ft_strchr(set, s[a]))
		return (a);
	return (-1);
}
