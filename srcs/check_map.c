/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:02:57 by cvine             #+#    #+#             */
/*   Updated: 2022/01/31 19:16:28 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *map, char *line)
{
	int	i;

	i = 1;
	while (i != map->width - 1)
	{
		if (line[i] == 'E')
			map->exit_num++;
		else if (line[i] == 'C')
			map->collect_num++;
		else if (line[i] == 'P')
			map->player_num++;
		i++;
	}
}

void	check_walls(t_game *map, int width, char *line)
{
	int	i;

	i = 0;
	if (!line && map->end_of_map)
		error("Error\nAn empty map or a hole in the bottom wall");
	if ((line && !map->end_of_map) || !width)
		return ;
	if (width != map->width)
		error("Error\nMap is not rectangular");
	while (line[i] && line[i] != '\n' && line[i] == '1')
		i++;
	if (map->height > 1 && (line[i] == '\0' || line[i] == '\n'))
	{
		map->end_of_map = 0;
		return ;
	}
	if ((map->height == 1 && line[i] && line[i] != '1' && line[i] != '\n')
		|| (line[0] != '1' || line[width - 1] != '1'))
		error("Error\nHole in the wall");
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
		if (width && !map->width)
			map->width = width;
		if (width)
			map->height++;
		check_walls(map, width, line);
		free(line);
		line = get_next_line(fd);
	}
	if (map->end_of_map)
		check_walls(map, width, line);
	if (!(map->exit_num) || !(map->collect_num) || map->player_num != 1)
		error("Error\nWrong map composition");
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		error("Error\nWrong argc");
	if (ft_strlen(argv[1]) < 5)
		error("Error\nWrong filename");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error("Error\nWrong file extension");
}
