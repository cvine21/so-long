/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:43 by cvine             #+#    #+#             */
/*   Updated: 2022/01/30 19:57:16 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

// typedef struct s_so_long
// {

// }	t_so_long;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

// typedef struct	s_img
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int		width;
// 	int		height;
// 	char	*path;
// }	t_img;

// typedef struct	s_dwg
// {
// 	void	*wall;
// 	void	*player;
// 	void	*exit;
// 	void	*ground;
// 	void	*collectible;
// }	t_dwg;

typedef struct s_map
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*ground;
	void	*collectible;

	char	**content;
	int		width;
	int		height;
	int		exit_num;
	int		player_num;
	int		collect_num;
	int		end_of_map;
}	t_map;

t_map	*map_init(void);
void	draw_map(t_vars *vars, t_map *map, int width, int height);

void	error(char *errname);
void	check_args(int argc, char **argv);
void	check_map(t_map	*map, char *line, int fd);
void	create_map(char *argv, t_map *map);

#endif