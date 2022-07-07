#include "../HEADER/push_swap.h"

int	min_size(t_stack *n)
{
	int	i;
	int	min_size;

	i = 1;
	min_size = n->stack[0];
	while (i < n->unsorted_size)
	{
		if (n->stack[i++] < min_size)
			min_size = n->stack[i];
	}
	return (min_size);
}
