#include "../HEADER/push_swap.h"
#include "../printfd/HEADER/ft_printfd.h"

void	exit_error(char *str)
{
	ft_printfd(2, "%s\n", str);
	exit(1);
}