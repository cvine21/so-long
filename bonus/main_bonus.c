/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:03:05 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 16:05:30 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_enemy(t_game *game, int wh, char *name, int flag)
{
	game->wing_flag = flag;
	game->img.enemy = mlx_xpm_file_to_image(game->mlx, name, &wh, &wh);
}

void	choose_dir(t_game *game, char **map, int i, int j)
{
	if ((map[i][j] == 'X' && map[i][j - 1] != '1')
		|| (map[i][j] == 'x' && map[i][j + 1] == '1'))
	{
		map[i][j] = '0';
		map[i][j - 1] = 'X';
	}
	else if ((map[i][j] == 'X' && map[i][j - 1] == '1')
			|| (map[i][j] == 'x' && map[i][j + 1] != '1'))
	{
		map[i][j] = '0';
		map[i][j + 1] = 'x';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, X * j, Y * i);
	// else if (map[i][j] == 'C')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->img.collectible, X * j, Y * i);
}

void	move_enemy(t_game *game, char **map, int i, int j)
{
	static int delay;

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
				mlx_put_image_to_window(game->mlx, game->win, game->img.ground, X * j, Y * i);
				mlx_put_image_to_window(game->mlx, game->win, game->img.enemy, X * j, Y * i);
			}
		}
	}
}

int	handle_enemy(t_game *game)
{
	mlx_do_sync(game->mlx);
	if (!game->wing_flag)
		animate_enemy(game, 0, ENEMY1, 1);
	else if (game->wing_flag == 1)
		animate_enemy(game, 0, ENEMY2, 2);
	else if (game->wing_flag == 2)
		animate_enemy(game, 0, ENEMY3, 3);
	else if (game->wing_flag == 3)
		animate_enemy(game, 0, ENEMY4, 4);
	else if (game->wing_flag == 4)
		animate_enemy(game, 0, ENEMY5, 5);
	else if (game->wing_flag == 5)
		animate_enemy(game, 0, ENEMY6, 6);
	else if (game->wing_flag == 6)
		animate_enemy(game, 0, ENEMY, 0);
	move_enemy(game, game->map, -1, -1);
	render_enemy(game, -1, -1);
	return (0);
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

int	main(int argc, char **argv)
{
	t_game	*game;

	game = map_init();
	check_args (argc, argv);
	create_map (argv[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->img.width * X, game->img.height * Y, "so_long");
	draw_map(game, 0, 0);
	mlx_key_hook(game->win, key_up, game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, DESTROY, 1L << 0, close_window, game);
	mlx_loop_hook(game->mlx, handle_enemy, game);
	mlx_loop(game->mlx);
}
