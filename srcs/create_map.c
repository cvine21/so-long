/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:46 by cvine             #+#    #+#             */
/*   Updated: 2022/01/31 19:16:28 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *argv, int fd)
{
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Opening the fd failed");
		exit (1);
	}
	return (fd);
}

void	fill_map(t_game *map, int fd, char *argv, char *line)
{
	int	i;

	i = 0;
	map->content = malloc(sizeof(char *) * map->height);
	if (!map->content)
	{
		perror("Allocation of memory to map->content failed");
		exit (1);
	}
	fd = open_map(argv, 0);
	line = get_next_line(fd);
	while (line)
	{
		map->content[i] = ft_strtrim(line, "\n");
		if (!map->content[i])
			error("Error\nMap content memory allocation failure");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

t_game	*map_init(void)
{
	t_game	*map;

	map = malloc(sizeof(t_game));
	if (!map)
	{
		perror("Allocation of memory to map failed");
		exit (1);
	}
	map->width = 0;
	map->height = 0;
	map->player_num = 0;
	map->collect_num = 0;
	map->exit_num = 0;
	map->end_of_map = 1;
	return (map);
}

void	create_map(char *argv, t_game	*map)
{
	int		fd;

	fd = open_map(argv, 0);
	check_map(map, NULL, fd);
	close(fd);
	fill_map(map, 0, argv, NULL);
}
