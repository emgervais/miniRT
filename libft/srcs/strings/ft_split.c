/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:12:55 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/18 18:58:09 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	a;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!split)
		return (NULL);
	a = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s && *s != c)
		{
			if (ft_int_strchr(s, c) != -1)
				split[a++] = ft_substr(s, 0, ft_int_strchr(s, c));
			else
				split[a++] = ft_substr(s, 0, ft_int_strchr(s, '\0'));
			while (*s && *s != c)
				s++;
		}
	}
	split[a] = NULL;
	return (split);
}

char	**ft_split_set(const char *s, const char *set)
{
	char	**split;
	size_t	a;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_word_set(s, set) + 1));
	if (!split)
		return (NULL);
	a = 0;
	while (*s)
	{
		while (ft_strchr(set, *s))
			++s;
		if (*s && !ft_strchr(set, *s))
		{
			if (ft_int_strchr_set(s, set) != -1)
				split[a++] = ft_substr(s, 0, ft_int_strchr_set(s, set));
			else
				split[a++] = ft_substr(s, 0, ft_int_strchr_set(s, "\0"));
			while (*s && !ft_strchr(set, *s))
				s++;
		}
	}
	split[a] = NULL;
	return (split);
}
