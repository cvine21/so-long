/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:05:08 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_atoi(const char *str)
{
	long int	rep;
	int			minus;

	rep = 0;
	minus = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		rep = rep * 10 + (*str - 48);
		if (rep < 0)
		{
			if (1 == minus)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return (rep * minus);
}
