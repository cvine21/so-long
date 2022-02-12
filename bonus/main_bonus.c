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

int	handle_enemy(t_game *game)
{
	int i;
	int j;

	i = -1;
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
	while (++i < game->img.height)
	{
		j = -1;
		while (++j < game->img.width)
		{
			if (game->map[i][j] == 'X')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img.ground, PIXEL * j, PIXEL * i);
				mlx_put_image_to_window(game->mlx, game->win, game->img.enemy, PIXEL * j, PIXEL * i);
			}
		}
	}
	return (0);
}

int	key_up(int keysym, t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
				PIXEL * game->hero.x, PIXEL * game->hero.y);
	if (keysym == W || keysym == A || keysym == S || keysym == D)
		game->hero.move_flag = 0;
	if (!game->hero.dir_flag)
		game->img.player = mlx_xpm_file_to_image(game->mlx,
			RIGHT, &width, &height);
	else
		game->img.player = mlx_xpm_file_to_image(game->mlx,
			LEFT, &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			PIXEL * game->hero.x, PIXEL * game->hero.y);
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
			game->img.width * PIXEL, game->img.height * PIXEL, "so_long");
	draw_map(game, 0, 0);
	mlx_loop_hook(game->mlx, handle_enemy, game);
	mlx_key_hook(game->win, key_up, game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, DESTROY, 1L << 0, close_window, game);
	mlx_loop(game->mlx);
}
