/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:02:57 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 15:46:02 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *map, char *line)
{
	int	i;

	i = 1;
	while (i != map->img.width - 1)
	{
		if (line[i] == 'E')
			map->e_num++;
		else if (line[i] == 'C')
			map->c_num++;
		else if (line[i] == 'P')
			map->p_num++;
		i++;
	}
}

void	check_walls(t_game *map, int width, char *line)
{
	int	i;

	i = 0;
	if (!line && map->end_of_map)
		terminate("Error\nAn empty map or a hole in the bottom wall", 1);
	if ((line && !map->end_of_map) || !width)
		return ;
	if (width != map->img.width)
		terminate("Error\nMap is not rectangular", 1);
	while (line[i] && line[i] != '\n' && line[i] == '1')
		i++;
	if (map->img.height > 1 && (line[i] == '\0' || line[i] == '\n'))
	{
		map->end_of_map = 0;
		return ;
	}
	if ((map->img.height == 1 && line[i] && line[i] != '1' && line[i] != '\n')
		|| (line[0] != '1' || line[width - 1] != '1'))
		terminate("Error\nHole in the wall", 1);
	check_chars(map, line);
}

void	check_map(t_game	*map, char *line, int fd)
{
	int	i;
	int	width;

	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		if (!strrchr(line, '\n'))
			width = ft_strlen(line);
		else
			width = ft_strlen(line) - 1;
		if (width && !map->img.width)
			map->img.width = width;
		if (width)
			map->img.height++;
		check_walls(map, width, line);
		free(line);
		line = get_next_line(fd);
	}
	if (map->end_of_map)
		check_walls(map, width, line);
	if (!(map->e_num) || !(map->c_num) || map->p_num != 1)
		terminate("Error\nWrong map composition", 1);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		terminate("Error\nWrong argc", 1);
	if (ft_strlen(argv[1]) < 5)
		terminate("Error\nWrong filename", 1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		terminate("Error\nWrong file extension", 1);
}
