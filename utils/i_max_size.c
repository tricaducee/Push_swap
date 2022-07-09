#include "../HEADER/push_swap.h"

int	i_max_size(t_stack *n)
{
	unsigned int	i;
	int				max_size;
	unsigned int	ret;

	i = 0;
	ret = 0;
	max_size = n->stack[0];
	while (i < n->current_size - 1)
	{
		if (n->stack[++i] > max_size)
		{
			max_size = n->stack[i];
			ret = i;
		}
	}
	return (ret);
}
