/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:21:30 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/19 20:42:51 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
				count++;
			in_word = 1;
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int			word_count = count_words(s, c);
	char		**result = (char **)malloc((word_count + 1) * sizeof(char *));
	int			i = 0;
	const char	*start;

	if (!result)
		return (NULL);
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		result[i++] = ft_substr(start, 0, s - start);
		if (!result[i - 1])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
	}
	result[i] = NULL;
	return (result);
}
