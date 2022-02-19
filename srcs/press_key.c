/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:45:42 by cvine             #+#    #+#             */
/*   Updated: 2022/02/19 12:13:39 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

void	print_moves(t_game *game)
{
	ft_putstr_fd("MOVES: ", 1);
	ft_putnbr_fd(game->hero.moves, 1);
	ft_putendl_fd("", 1);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map[game->hero.y + y][game->hero.x + x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		X * game->hero.x, Y * game->hero.y);
	if (game->map[game->hero.y][game->hero.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			X * game->hero.x, Y * game->hero.y);
	game->hero.x += x;
	game->hero.y += y;
	game->hero.moves++;
	if (game->map[game->hero.y][game->hero.x] == 'C')
	{
		game->c_num--;
		game->map[game->hero.y][game->hero.x] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		X * game->hero.x, Y * game->hero.y);
	print_moves(game);
	if (game->map[game->hero.y][game->hero.x] == 'E' && !game->c_num)
		terminate("YOU WON!", 0);
	if (game->map[game->hero.y][game->hero.x] == 'E' && game->c_num)
		ft_putendl_fd("Sorry, collect all the aplles", 1);
}

int	press_key(int keysym, t_game *game)
{
	if (keysym == ESC)
		close_window(game);
	else if (keysym == W)
		move_player(game, 0, -1);
	else if (keysym == A)
		move_player(game, -1, 0);
	else if (keysym == S)
		move_player(game, 0, 1);
	else if (keysym == D)
		move_player(game, 1, 0);
	return (0);
}
