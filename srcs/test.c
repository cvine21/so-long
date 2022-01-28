/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:03:05 by cvine             #+#    #+#             */
/*   Updated: 2022/01/28 19:47:30 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	dst = data->addr + (x * 4 + data->line_length *  y);
// 	*(unsigned int *)dst = color;
// }

// int	ft_close(int keycode, t_vars *vars)
// {
// 	(void) keycode;
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

int main(int argc, char **argv)
{
	// t_vars	vars;
	// // t_img	img;
	// void	*image;
	// int		width;
	// int		height;
	check_map(argc, argv);
	read_map(argv[1]);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello world!");
	// image = mlx_xpm_file_to_image(vars.mlx, "./assets/lIdle_0_bigger.xpm", &width, &height);
	// if (!image)
	// {
	// 	perror("ERROR");
	// 	return (1);
	// }
	// // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_put_image_to_window(vars.mlx, vars.win, image, 64*10, 64*10);
	// mlx_loop(vars.mlx);
}

// int main(int argc, char	**argv)
// {
	
// 	return (0);
// }