NAME		=	so_long

LIBFT_DIR	=	libft/

MLX_DIR		=	minilibx_opengl_20191021/

SRCS_DIR	=	srcs/

B_SRCS_DIR	= 	bonus/

HEADER_DIR	=	includes/

LIBFT		=	libft.a

SRCS_LST	=	so_long.c		check_map.c		terminate.c\
				create_map.c	draw_map.c		press_key.c

B_SRCS_LST	=	so_long_bonus.c		check_map_bonus.c	terminate_bonus.c\
				create_map_bonus.c	draw_map_bonus.c	press_key_bonus.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

B_SRCS		= 	$(addprefix $(B_SRCS_DIR), $(B_SRCS_LST))

HEADER		=	$(addprefix $(HEADER_DIR), so_long.h)

B_HEADER	= 	$(addprefix $(HEADER_DIR), so_long_bonus.h)

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

B_OBJS		=	$(patsubst %.c, %.o, $(B_SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_DIR) -I$(LIBFT_DIR)$(HEADER_DIR) -I$(MLX_DIR)

LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

RM			=	rm -f

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(SRCS) -o $(NAME)

bonus		: 	$(B_OBJS) $(B_HEADER)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(B_SRCS) -o $(NAME)

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(B_OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re			:	fclean all