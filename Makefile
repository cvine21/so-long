NAME		=	so_long

LIBFT_PATH	=	libft/

SRCS_PATH	=	srcs/

B_SRCS_PATH	= 	bonus/

HEADER_PATH	=	includes/

LIBFT		=	libft.a

SRCS_LST	=	so_long.c		check_map.c		terminate.c\
				create_map.c	draw_map.c		press_key.c

B_SRCS_LST	=	so_long_bonus.c		check_map_bonus.c	terminate_bonus.c\
				create_map_bonus.c	draw_map_bonus.c	press_key_bonus.c

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LST))

B_SRCS		= 	$(addprefix $(B_SRCS_PATH), $(B_SRCS_LST))

HEADER		=	$(addprefix $(HEADER_PATH), so_long.h)

B_HEADER	= 	$(addprefix $(HEADER_PATH), so_long_bonus.h)

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

B_OBJS		=	$(patsubst %.c, %.o, $(B_SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH) -I$(LIBFT_PATH)$(HEADER_PATH) -I./minilibx_opengl_20191021

LIBFT_FLAGS	=	-L$(LIBFT_PATH) -lft

MLX_FLAGS	=	-L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

RM			=	rm -f

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(SRCS) -o $(NAME)

bonus		: 	$(B_OBJS) $(B_HEADER)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(B_SRCS) -o $(NAME)

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS) $(B_OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re			:	fclean all