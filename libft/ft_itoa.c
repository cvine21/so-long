/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:27:46 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_nlen(int n)
{
	int	nlen;

	nlen = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n = -n;
		nlen++;
	}
	while (n)
	{
		nlen++;
		n /= 10;
	}
	return (nlen);
}

static char	*represent(char *rep, int n, int nlen)
{
	int	stop;

	stop = 0;
	if (n < 0)
	{
		*rep = '-';
		n = -n;
		stop++;
	}
	rep[nlen] = '\0';
	while (nlen-- != stop)
	{
		rep[nlen] = n % 10 + 48;
		n /= 10;
	}
	return (rep);
}

char	*ft_itoa(int n)
{
	char	*rep;
	int		nlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nlen = ft_nlen(n);
	rep = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!rep)
		return (NULL);
	return (represent(rep, n, nlen));
}
