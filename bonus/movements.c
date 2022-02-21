/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:56:09 by cvine             #+#    #+#             */
/*   Updated: 2022/02/21 17:04:58 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*moves;
	char	*num;

	mlx_put_image_to_window(game->mlx, game->win, game->img.banner1, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.banner2, X, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.banner3, X * 2, 0);
	moves = ft_strdup("MOVES: ");
	num = ft_itoa(game->hero.moves);
	mlx_string_put(game->mlx, game->win, X, Y / 1.75, 0x0, moves);
	mlx_string_put(game->mlx, game->win, X * 1.7, Y / 1.75, 0x0, num);
	free(moves);
	free(num);
}

void	choose_dir(t_game *game, char **map, int i, int j)
{
	if (map[i][j - 1] != '0' && map[i][j + 1] != '0')
		return ;
	if ((map[i][j] == 'X' && map[i][j - 1] == '0')
		|| (map[i][j] == 'x' && map[i][j + 1] != '0'))
	{
		map[i][j] = '0';
		map[i][j - 1] = 'X';
	}
	else if ((map[i][j] == 'X' && map[i][j - 1] != '0')
			|| (map[i][j] == 'x' && map[i][j + 1] == '0'))
	{
		map[i][j] = '0';
		map[i][j + 1] = 'x';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		X * j, Y * i);
}

void	move_enemy(t_game *game, char **map, int i, int j)
{
	static int	delay;

	if (++delay == 21)
		delay = 0;
	else
		return ;
	while (++i < game->img.height)
	{
		j = -1;
		while (++j < game->img.width)
		{
			if (map[i][j] == 'X' || map[i][j] == 'x')
			{
				choose_dir(game, game->map, i, j);
				j++;
			}
		}
	}
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map[game->hero.y + y][game->hero.x + x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		X * game->hero.x, Y * game->hero.y);
	if (game->map[game->hero.y][game->hero.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, X * game->hero.x, Y * game->hero.y);
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
	if (game->map[game->hero.y][game->hero.x] == 'X')
		terminate("WASTED", 0);
}
