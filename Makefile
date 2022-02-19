NAME		=	so_long

LIBFT_DIR	=	libft/

MLX_DIR		=	minilibx_opengl_20191021/

SRCS_DIR	=	srcs/

BSRCS_DIR	= 	bonus/

HEADER_DIR	=	includes/

SRCS_LST	=	main.c			parse.c			terminate.c\
				create_map.c	render_map.c	press_key.c

BSRCS_LST	=	main_bonus.c		parse_bonus.c	terminate_bonus.c\
				create_map_bonus.c	render_map_bonus.c	handle_keys.c\
				animations.c		movements.c			handle_enemy.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

BSRCS		= 	$(addprefix $(BSRCS_DIR), $(BSRCS_LST))

HEADER		=	$(addprefix $(HEADER_DIR), so_long.h)

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

BOBJS		=	$(patsubst %.c, %.o, $(BSRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_DIR) -I$(LIBFT_DIR)$(HEADER_DIR) -I$(MLX_DIR)

LFT_FLAGS	=	-L$(LIBFT_DIR) -lft

MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

RM			=	rm -f

ifdef BONUS
	OBJECTS = $(BOBJS)
else
	OBJECTS = $(OBJS)
endif

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJECTS) $(HEADER)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LFT_FLAGS) $(MLX_FLAGS) $(OBJECTS) -o $@

bonus		:
	@make BONUS=1 all

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(BOBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re			:	fclean all