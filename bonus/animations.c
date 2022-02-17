/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:50:51 by cvine             #+#    #+#             */
/*   Updated: 2022/02/17 12:37:47 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate(t_game *game, char *name, int flag, char c)
{
	int	w;
	int	h;

	if (c == 'E')
	{
		game->wing_flag = flag;
		game->img.enemy = mlx_xpm_file_to_image(game->mlx, name, &w, &h);
	}
	else if (c == 'P')
	{
		game->hero.move_flag = flag;
		game->img.player = mlx_xpm_file_to_image(game->mlx, name, &w, &h);
	}
}

void	animate_player(t_game *game)
{
	if (!game->hero.dir_flag)
	{
		if (!game->hero.move_flag || game->hero.move_flag == 2)
			animate(game, RIGHT1, 1, 'P');
		else if (game->hero.move_flag == 1)
			animate(game, RIGHT2, 2, 'P');
	}
	else
	{
		if (!game->hero.move_flag || game->hero.move_flag == 2)
			animate(game, LEFT1, 1, 'P');
		else if (game->hero.move_flag == 1)
			animate(game, LEFT2, 2, 'P');
	}
}

void	animate_enemy(t_game *game)
{
	if (!game->wing_flag)
		animate(game, ENEMY1, 1, 'E');
	else if (game->wing_flag == 1)
		animate(game, ENEMY2, 2, 'E');
	else if (game->wing_flag == 2)
		animate(game, ENEMY3, 3, 'E');
	else if (game->wing_flag == 3)
		animate(game, ENEMY4, 4, 'E');
	else if (game->wing_flag == 4)
		animate(game, ENEMY5, 5, 'E');
	else if (game->wing_flag == 5)
		animate(game, ENEMY6, 6, 'E');
	else if (game->wing_flag == 6)
		animate(game, ENEMY, 0, 'E');
}
