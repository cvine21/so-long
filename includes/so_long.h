/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:43 by cvine             #+#    #+#             */
/*   Updated: 2022/01/31 19:16:55 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# define W			119
# define A			115
# define S			97
# define D			100
# define ESC		97307
# define DESTROY	17
# define PXL_HEIGHT	64
# define PXL_WIDTH	64

// typedef struct s_so_long
// {

// }	t_so_long;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

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

typedef struct s_game
{
	char		**content;
	void		*wall;
	void		*player;
	void		*exit;
	void		*ground;
	void		*collectible;
	int			width;
	int			height;
	int			exit_num;
	int			player_num;
	int			collect_num;
	int			end_of_map;
}	t_game;

void	handle_keypress(int keysym, t_vars *vars, t_game *map);
void	xmp_to_img(t_vars *vars, t_game *map, int width, int height);
t_game	*map_init(void);
void	draw_map(t_vars *vars, t_game *map);

void	error(char *errname);
void	check_args(int argc, char **argv);
void	check_map(t_game	*map, char *line, int fd);
void	create_map(char *argv, t_game *map);

#endif