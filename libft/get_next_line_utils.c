/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:13:47 by cvine             #+#    #+#             */
/*   Updated: 2022/01/28 19:44:48 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

char	*find_newline(const char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	bufsize;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	bufsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	joint = (char *)malloc(sizeof(char) * bufsize);
	if (!joint)
		return (NULL);
	i = -1;
	while (s1[++i])
		joint[i] = s1[i];
	j = -1;
	while (s2[++j])
		joint[i + j] = s2[j];
	joint[i + j] = '\0';
	free((char *)s1);
	return (joint);
}
