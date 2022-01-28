/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:49:11 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_trimlen(char const *s1, char const *set)
{
	size_t	trimlen;
	int		i;

	i = 0;
	trimlen = ft_strlen(s1);
	if (!*s1)
		return (0);
	while (s1[trimlen - 1] && set[i])
	{
		if (s1[trimlen - 1] != set[i])
			i++;
		else
		{
			trimlen--;
			i = 0;
		}
	}
	return (trimlen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && set[i])
	{
		if (*s1 != set[i])
			i++;
		else
		{
			s1++;
			i = 0;
		}
	}
	trimmed = ft_substr(s1, 0, ft_trimlen(s1, set));
	return (trimmed);
}
