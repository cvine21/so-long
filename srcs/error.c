#include "so_long.h"

void	error(char *errname)
{
	ft_putendl_fd(errname, 2);
	exit (1);
}