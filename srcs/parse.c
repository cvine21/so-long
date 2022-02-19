/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:02:57 by cvine             #+#    #+#             */
/*   Updated: 2022/02/19 12:13:38 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *map, char *line)
{
	int	i;

	i = -1;
	while (++i != map->img.width - 1)
	{
		if (line[i] == 'E')
			map->e_num++;
		else if (line[i] == 'C')
			map->c_num++;
		else if (line[i] == 'P')
		{
			map->p_num++;
			map->hero.x = i;
			map->hero.y = map->img.height - 1;
		}
		else if (line[i] != '0' && line[i] != '1')
			terminate("Error\nUnknown character on the map", 1);
	}
}

void	check_walls(t_game *map, int width, char *line)
{
	int	i;

	i = 0;
	map->bottom_wall = 1;
	if (width != map->img.width)
		terminate("Error\nMap is not rectangular", 1);
	while (line[i] == '1')
		i++;
	if (map->img.height > 1 && (!line[i] || line[i] == '\n'))
		map->bottom_wall = 0;
	if (map->img.height == 1 && line[i] && line[i] != '\n')
		terminate("Hole or unknown character in the upper wall", 1);
	if (line[0] != '1' || line[width - 1] != '1')
		terminate("Error\nHole in the side wall", 1);
	check_chars(map, line);
}

void	check_map(t_game *map, char *line, int fd)
{
	int	width;

	if (!line)
		terminate("Error\nEmpty map", 1);
	while (line)
	{
		width = ft_strlen(line);
		if (*line == '\n' || !width)
			terminate("Error\nEmpty line", 1);
		if (strrchr(line, '\n'))
			width--;
		if (!map->img.width)
			map->img.width = width;
		map->img.height++;
		check_walls(map, width, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!line && map->bottom_wall)
		terminate("Error\nHole in the bottom wall", 1);
	if ((!(map->e_num) || !(map->c_num) || map->p_num != 1))
		terminate("Error\nWrong map composition", 1);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		terminate("Error\nInvalid number of arguments", 1);
	if (ft_strlen(argv[1]) < 5)
		terminate("Error\nInvalid map", 1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		terminate("Error\nThe map must have an extension \".ber\"", 1);
}
