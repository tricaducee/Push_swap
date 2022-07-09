#include "../HEADER/push_swap.h"

int	i_min_size(t_stack *n)
{
	unsigned int	i;
	int				min_size;
	unsigned int	ret;

	i = 0;
	ret = 0;
	min_size = n->stack[0];
	while (i < n->current_size - 1)
	{
		if (n->stack[++i] < min_size)
		{
			min_size = n->stack[i];
			ret = i;
		}
	}
	return (ret);
}
