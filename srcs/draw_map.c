/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:05:15 by cvine             #+#    #+#             */
/*   Updated: 2022/01/31 19:16:28 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xmp_to_img(t_vars *vars, t_game *map, int width, int height)
{
	map->wall= mlx_xpm_file_to_image(vars->mlx, "./assets/Idle.xpm", &width, &height);
	map->ground = mlx_xpm_file_to_image(vars->mlx, "./assets/green.xpm", &width, &height);
	map->player = mlx_xpm_file_to_image(vars->mlx, "./assets/Idle32x32.xpm", &width, &height);
	map->collectible = mlx_xpm_file_to_image(vars->mlx, "./assets/apple.xpm", &width, &height);
	map->exit = mlx_xpm_file_to_image(vars->mlx, "./assets/exit.xpm", &width, &height);
}

void	draw_map(t_vars *vars, t_game *map)
{
	int i;
	int j;

	i = 0;
	xmp_to_img(vars, map, 0, 0);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, map->ground, 64 * j, 64 * i);
			if (map->content[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, map->wall, 64 * j, 64 * i);
			else if (map->content[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, map->player, 64 * j, 64 * i);
			else if (map->content[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, map->collectible, 64 * j, 64 * i);
			else if (map->content[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, map->exit, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}