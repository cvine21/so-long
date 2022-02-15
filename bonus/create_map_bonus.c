/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:46 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 15:46:02 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	fill_map(t_game *game, int fd, char *argv, char *line)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * game->img.height);
	if (!game->map)
	{
		perror("Allocation of memory to map->content failed");
		exit (1);
	}
	fd = open_map(argv, 0);
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strtrim(line, "\n");
		if (!game->map[i])
			terminate("Error\nMap content memory allocation failure", 1);
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
	map->img.width = 0;
	map->img.height = 0;
	map->p_num = 0;
	map->c_num = 0;
	map->e_num = 0;
	map->end_of_map = 1;
	map->hero.moves = 0;
	map->hero.move_flag = 0;
	map->hero.dir_flag = 0;
	map->wing_flag = 0;
	map->dir_flag = 0;
	map->enemy_flag = 0;
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
