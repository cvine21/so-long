/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:05:15 by cvine             #+#    #+#             */
/*   Updated: 2022/02/17 12:46:50 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, int j, int i)
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
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.player, X * j, Y * i);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.collectible, X * j, Y * i);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.exit, X * j, Y * i);
		}
	}
}

void	render_map(t_game *game, int w, int h)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &w, &h);
	game->img.ground = mlx_xpm_file_to_image(game->mlx, GROUND, &w, &h);
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &w, &h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, COLLECT, &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &w, &h);
	put_image(game, -1, -1);
}
