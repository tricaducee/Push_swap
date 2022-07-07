#include "../HEADER/push_swap.h"

void	push_chunk(t_stack *a, t_stack *b, int min_size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = a->unsorted_size;
	while (i < len)
	{
		if (a->stack[0] >= min_size)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}