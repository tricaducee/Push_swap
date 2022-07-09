#include "../HEADER/push_swap.h"

int	sorted_checker(t_stack *n)
{
	unsigned int	i;

	i = 0;
	while (i < n->current_size - 1)
	{
		if (n->stack[i] > n->stack[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
