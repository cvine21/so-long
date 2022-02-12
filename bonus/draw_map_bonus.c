/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:05:15 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 16:05:30 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xpm_to_img(t_game *game, int j, int i)
{
	while (++i < game->img.height)
	{
		j = -1;
		while (++j < game->img.width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.ground, PIXEL * j, PIXEL * i);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.wall, PIXEL * j, PIXEL * i);
			else if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.player, PIXEL * j, PIXEL * i);
				game->hero.x = j;
				game->hero.y = i;
			}
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.collectible, PIXEL * j, PIXEL * i);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.exit, PIXEL * j, PIXEL * i);
			else if (game->map[i][j] == 'X')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.enemy, PIXEL * j, PIXEL * i);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.sword, 0, 0);
}

void	draw_map(t_game *game, int width, int height)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
	game->img.ground = mlx_xpm_file_to_image(game->mlx,
			GROUND, &width, &height);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			PLAYER, &width, &height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			COLLECT, &width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx, ENEMY, &width, &height);
	game->img.sword = mlx_xpm_file_to_image(game->mlx, SWORD, &width, &height);
	xpm_to_img(game, -1, -1);
}
