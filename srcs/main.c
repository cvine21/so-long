/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:03:05 by cvine             #+#    #+#             */
/*   Updated: 2022/02/19 12:13:36 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = game_init();
	check_args (argc, argv);
	create_map (argv[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->img.width * X, game->img.height * Y, "so_long");
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, DESTROY, 1L << 0, close_window, game);
	mlx_loop(game->mlx);
}
