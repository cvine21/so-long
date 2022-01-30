/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:22:04 by cvine             #+#    #+#             */
/*   Updated: 2022/01/29 18:59:07 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	s += slen;
	if (*s == (char)c)
		return ((char *)s);
	while (slen > 0)
	{
		s--;
		if (*s == (char)c)
			return ((char *)s);
		slen--;
	}
	return (NULL);
}
