#include "../HEADER/push_swap.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	exit_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}