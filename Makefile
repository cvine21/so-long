NAME		=	so_long

LIBFT_PATH	=	libft/

SRCS_PATH	=	srcs/

HEADER_PATH	=	includes/

LIBFT		=	libft.a

SRCS_LST	=	test.c	check_map.c	error.c	read_map.c

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LST))

HEADER		=	$(addprefix $(HEADER_PATH), so_long.h)

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH) -I$(LIBFT_PATH)$(HEADER_PATH) -Imlx

LIBFT_FLAGS	=	-L$(LIBFT_PATH) -lft

MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

RM			=	rm -f

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(SRCS) -o $(NAME)

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re			:	fclean all