/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:21:52 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	h;
	unsigned int	n;

	h = 0;
	n = 0;
	if (!needle[n])
		return ((char *)haystack);
	while (haystack[h] && h < len)
	{
		n = 0;
		while (needle[n] == haystack[h + n] && h + n < len)
		{
			n++;
			if (!needle[n])
				return ((char *)(haystack + h));
		}
		h++;
	}
	return (NULL);
}
