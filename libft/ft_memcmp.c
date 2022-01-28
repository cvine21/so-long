/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:18:39 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	i;
	unsigned char	*sp1;
	unsigned char	*sp2;

	i = 0;
	sp1 = (unsigned char *)s1;
	sp2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*sp1 == *sp2 && i < n - 1)
	{
		sp1++;
		sp2++;
		i++;
	}
	return (*sp1 - *sp2);
}
