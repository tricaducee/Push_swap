#include "../print_stacks_cmd/print_stacks_cmd.h"

void	push_chunk(t_stack *a, t_stack *b, int min_size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = a->unsorted_size;
	while (i < len)
	{
		if (a->stack[0] >= min_size)
			p_pb(a, b, 1, TIME);
		else
			p_ra(a, b, 1, TIME);
		i++;
	}
}