/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:21:30 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/08/16 19:39:12 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *s, char c);
static char		*ft_strndup(const char *s, size_t n);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	**r;

	r = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			l = 0;
			while (s[i + l] && s[i + l] != c)
				l++;
			r[j++] = ft_strndup(s + i, l);
			i += l;
		}
		else
			i++;
	}
	r[j] = NULL;
	return (r);
}

static size_t	ft_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
		{
			while (s[i] && s[i] == c)
				i++;
		}
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
