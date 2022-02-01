/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:45:42 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 15:58:17 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	if (game->map[game->hero.y + y][game->hero.x + x] == '1')
		return ;
	if (game->map[game->hero.y + y][game->hero.x + x] == 'E' && !game->c_num)
	{
		printf("YOU WON!\n");
		exit (0);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
			PXL_WIDTH * game->hero.x, PXL_HEIGHT * game->hero.y);
	if (game->map[game->hero.y][game->hero.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			PXL_WIDTH * game->hero.x, PXL_HEIGHT * game->hero.y);
	game->hero.x += x;
	game->hero.y += y;
	game->hero.moves++;
	if (game->map[game->hero.y + y][game->hero.x + x] == 'C')
	{
		game->c_num--;
		game->map[game->hero.y][game->hero.x] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		PXL_WIDTH * game->hero.x, PXL_HEIGHT * game->hero.y);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == ESC)
		close_window(game);
	else if (keysym == W)
		move_player(game, 0, -1);
	else if (keysym == A)
		move_player(game, 0, 1);
	else if (keysym == S)
		move_player(game, 1, 0);
	else if (keysym == D)
		move_player(game, -1, 0);
	printf("MOVES:%d\n", game->hero.moves);
	return (0);
}