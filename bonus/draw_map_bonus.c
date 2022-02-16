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
				game->img.ground, X * j, Y * i);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.wall, X * j, Y * i);
			else if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.player, X * j, Y * i);
				game->hero.x = j;
				game->hero.y = i;
			}
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.collectible, X * j, Y * i);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.exit, X * j, Y * i);
			else if (game->map[i][j] == 'X')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.enemy, X * j, Y * i);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.banner1, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.banner2, X, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.banner3, X * 2, 0);
}

void	draw_map(t_game *game, int w, int h)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &w, &h);
	game->img.ground = mlx_xpm_file_to_image(game->mlx, GROUND, &w, &h);
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &w, &h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, COLLECT, &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &w, &h);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx, ENEMY, &w, &h);
	game->img.banner1 = mlx_xpm_file_to_image(game->mlx, BANNER1, &w, &h);
	game->img.banner2 = mlx_xpm_file_to_image(game->mlx, BANNER2, &w, &h);
	game->img.banner3 = mlx_xpm_file_to_image(game->mlx, BANNER3, &w, &h);
	xpm_to_img(game, -1, -1);
}