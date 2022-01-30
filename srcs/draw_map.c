/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:05:15 by cvine             #+#    #+#             */
/*   Updated: 2022/01/30 19:57:26 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xmp_to_img()
{

}

void	draw_map(t_vars *vars, t_map *map, int width, int height)
{
	int i;
	int j;

	i = 0;
	map->wall= mlx_xpm_file_to_image(vars->mlx, "./assets/bigger_rocky01.xpm", &width, &height);
	map->ground = mlx_xpm_file_to_image(vars->mlx, "./assets/ground05_bigger.xpm", &width, &height);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, map->wall, 64 * j, 64 * i);
			else if (map->content[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, map->ground, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}