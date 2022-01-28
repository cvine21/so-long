/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:43 by cvine             #+#    #+#             */
/*   Updated: 2022/01/28 19:19:14 by cvine            ###   ########.fr       */
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

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	char	*path;
}	t_img;

typedef struct	s_dwg
{
	t_img	*wall;
	t_img	*player;
	t_img	*exit;
	t_img	*ground;
	t_img	*collectible;
}	t_dwg;

typedef struct s_map
{
	char	**content;
	int		width;
	int		height;
	char	*exit_num;
	char	*player_num;
	char	*collect_num;
}	t_map;


void	error(char *errname);
void	check_map(int argc, char **argv);
void	check_walls(int height, int width, char *line);
void	read_map(char *argv);

#endif