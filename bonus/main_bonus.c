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

int	handle_enemy(t_game *game)
{
	if (!game->enemy.wing_flag)
		game->enemy.wing_flag = 1;
	else
		game->enemy.wing_flag = 0;
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
	mlx_key_hook(game->win, key_up, game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, DESTROY, 1L << 0, close_window, game);
	mlx_loop_hook(game->win, handle_enemy, game);
	mlx_loop(game->mlx);
}
