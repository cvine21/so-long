/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:45:42 by cvine             #+#    #+#             */
/*   Updated: 2022/02/19 12:13:17 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int	key_up(int keysym, t_game *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		X * game->hero.x, Y * game->hero.y);
	if (keysym == W || keysym == A || keysym == S || keysym == D)
		game->hero.move_flag = 0;
	if (!game->hero.dir_flag)
		game->img.player = mlx_xpm_file_to_image(game->mlx, RIGHT, &w, &h);
	else
		game->img.player = mlx_xpm_file_to_image(game->mlx, LEFT, &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		X * game->hero.x, Y * game->hero.y);
	return (0);
}

int	press_key(int keysym, t_game *game)
{
	if (keysym == ESC)
		close_window(game);
	if (keysym == W || keysym == A || keysym == S || keysym == D)
	{
		if (keysym == A)
			game->hero.dir_flag = 1;
		else if (keysym == D)
			game->hero.dir_flag = 0;
		animate_player(game);
		if (keysym == W)
			move_player(game, 0, -1);
		else if (keysym == A)
			move_player(game, -1, 0);
		else if (keysym == S)
			move_player(game, 0, 1);
		else if (keysym == D)
			move_player(game, 1, 0);
	}
	return (0);
}
