/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:03:33 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			num++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (num);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**memfree(char **split)
{
	while (*split)
	{
		free(*split);
		split++;
	}
	free(split);
	return (NULL);
}

static char	**get_splitted(char	**split, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (words--)
	{
		word_len = wordlen(s, c);
		split[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!split[i])
			return (memfree(split));
		while (*s == c)
			s++;
		ft_strlcpy (split[i], s, word_len + 1);
		s += word_len;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = get_splitted(split, s, c, words);
	return (split);
}
