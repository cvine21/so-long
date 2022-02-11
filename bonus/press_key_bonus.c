/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:45:42 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 16:05:30 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

void	print_moves(t_game *game)
{
	char	*moves;

	mlx_put_image_to_window(game->mlx, game->win,
			game->img.sword, PIXEL * 0, PIXEL * 0);
	moves = ft_strjoin("MOVES: ", ft_itoa(game->hero.moves));
	mlx_string_put(game->mlx, game->win, PIXEL * 0, PIXEL / 1.75, 0x0, moves);
	free(moves);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map[game->hero.y + y][game->hero.x + x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		PIXEL * game->hero.x, PIXEL * game->hero.y);
	if (game->map[game->hero.y][game->hero.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			PIXEL * game->hero.x, PIXEL * game->hero.y);
	game->hero.x += x;
	game->hero.y += y;
	game->hero.moves++;
	if (game->map[game->hero.y][game->hero.x] == 'C')
	{
		game->c_num--;
		game->map[game->hero.y][game->hero.x] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		PIXEL * game->hero.x, PIXEL * game->hero.y);
	print_moves(game);
	if (game->map[game->hero.y][game->hero.x] == 'E' && !game->c_num)
		terminate("YOU WON!", 0);
	if (game->map[game->hero.y][game->hero.x] == 'E' && game->c_num)
		printf("Sorry, collect all the aplles\n");
	if (game->map[game->hero.y][game->hero.x] == 'X')
		terminate("WASTED", 0);
}

int	press_key(int keysym, t_game *game)
{
	// int width;
	// int height;
	// static int i;

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
