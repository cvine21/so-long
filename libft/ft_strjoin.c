/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:42:33 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	bufsize;

	if (!s1 || !s2)
		return (NULL);
	bufsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 || !s2)
		return (NULL);
	joint = (char *)malloc(sizeof(char) * bufsize);
	if (!joint)
		return (NULL);
	ft_strlcpy(joint, s1, bufsize);
	ft_strlcat(joint, s2, bufsize);
	return (joint);
}
