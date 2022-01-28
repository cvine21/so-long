/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:59:36 by cvine             #+#    #+#             */
/*   Updated: 2022/01/28 19:56:40 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(int height, int width, char *line)
{
	int i;

	i = 0;
	if (ft_strrchr(line, '\n')) /*все строки кроме (возможно) последней)*/
	{
		while (line[i] && line[i] != '\n')
		{
			if ((!height && line[i] != '1')
			|| (height > 0 && (line[0] != '1' || line[width - 1] != '1')))
				error("Error\nHole in the upper wall");
			i++;
		}
	}
	else /*последняя строка*/
	{
		if (height < 3) /*меньше трех строк*/
			error("Error\nMap is composed incorrectly");
		while (line[i])
		{
			if (line[i] != '1')
				error("Error\nHole in the side wall");
			i++;
		}
	}
}

void	check_map(int argc, char **argv)
{
	if (argc != 2)
		error("Error\nWrong argc");
	if (ft_strlen(argv[1]) < 5)
		error("Error\nWrong filename");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error("Error\nWrong file extension");
}