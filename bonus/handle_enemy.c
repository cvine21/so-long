/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:12:09 by cvine             #+#    #+#             */
/*   Updated: 2022/02/17 12:38:31 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_enemy(t_game *game, int i, int j)
{
	while (++i < game->img.height)
	{
		j = -1;
		while (++j < game->img.width)
		{
			if (game->map[i][j] == 'X' || game->map[i][j] == 'x')
			{
				if (i == game->hero.y && j == game->hero.x)
					terminate("WASTED", 0);
				mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
					X * j, Y * i);
				mlx_put_image_to_window(game->mlx, game->win, game->img.enemy,
					X * j, Y * i);
			}
		}
	}
}

int	handle_enemy(t_game *game)
{
	mlx_do_sync(game->mlx);
	animate_enemy(game);
	move_enemy(game, game->map, -1, -1);
	render_enemy(game, -1, -1);
	return (0);
}
