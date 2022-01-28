/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:46 by cvine             #+#    #+#             */
/*   Updated: 2022/01/28 19:55:40 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_map	*map, char *line, int fd)
{
	int 	i;

	i = 0;
	while(line)
	{
		map->content[i] = ft_strtrim(line, "\n");
		check_walls(map->height, map->width, line);
		map->height++;
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

t_map	*map_init(char	*line)
{
	t_map	*map;
	
	map = malloc(sizeof(t_map));
	if(!map)
		error("Failed to allocate memory for the map");
	map->content = malloc(sizeof(char **));
	if (!map->content)
		error("Failed to allocate memory for the map content");
	map->width = ft_strlen(line) - 1;
	map->height = 0;
	map->player_num = 0;
	map->collect_num = 0;
	map->exit_num = 0;
	return (map);
}

void	read_map(char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error("Error\nFile cannot be opened");
	line = get_next_line(fd);
	if (!line)
		error("Error\nGnl issue");
	fill_map(map_init(line), line, fd);
	free(line);
	close(fd);
}