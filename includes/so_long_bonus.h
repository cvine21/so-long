/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:43 by cvine             #+#    #+#             */
/*   Updated: 2022/02/01 16:05:38 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define W			13
# define A			0
# define S			1
# define D			2
# define ESC		53
# define DESTROY	17
# define PIXEL		64
# define RIGHT		"./assets/rfrog.xpm"
# define RIGHT1		"./assets/rfrog1.xpm"
# define RIGHT2		"./assets/rfrog2.xpm"
# define LEFT		"./assets/lfrog.xpm"
# define LEFT1		"./assets/lfrog1.xpm"
# define LEFT2		"./assets/lfrog2.xpm"
# define WALL		"./assets/box.xpm"
# define GROUND		"./assets/green.xpm"
# define PLAYER		"./assets/rfrog.xpm"
# define COLLECT	"./assets/apple.xpm"
# define EXIT		"./assets/exit.xpm"
# define ENEMY1		"./assets/open_wings.xpm"
# define ENEMY2		"./assets/closed_wings.xpm"
# define SWORD		"./assets/Sword.xpm"

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	move_flag;
	int	dir_flag;
}	t_player;

typedef	struct  s_enemy
{
	int		wing_flag;
}	t_enemy;


typedef struct	s_img
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*ground;
	void	*collectible;
	void	*enemy;
	void	*sword;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	t_img		img;
	t_player	hero;
	t_enemy		enemy;
	void		*mlx;
	void		*win;
	char		**map;
	int			e_num;
	int			p_num;
	int			c_num;
	int			end_of_map;
}	t_game;

int		close_window(t_game *game);
int		press_key(int keysym, t_game *game);
void	xmp_to_img(t_game *map, int width, int height);
t_game	*map_init(void);
void	draw_map(t_game *game, int width, int height);

void	terminate(char *errname, int status);
void	check_args(int argc, char **argv);
void	check_map(t_game	*map, char *line, int fd);
void	create_map(char *argv, t_game *map);

#endif