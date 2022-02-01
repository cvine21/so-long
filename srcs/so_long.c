/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:03:05 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 12:55:52 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int main(int argc, char **argv)
{
	t_game	*game;
	
	game = map_init();
	check_args (argc, argv);
	create_map (argv[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
		game->img.width * PXL_WIDTH, game->img.height * PXL_HEIGHT, "so_long");
	draw_map(game, 0, 0);
	mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
	mlx_hook(game->win, DESTROY , 1L<<0, close_window, game);
	mlx_loop(game->mlx);
}
