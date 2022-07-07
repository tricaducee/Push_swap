#include "../print_stacks_cmd/print_stacks_cmd.h"

int	i_max_size(t_stack *n)
{
	int				i;
	int				max_size;
	unsigned int	ret;

	i = 0;
	ret = 0;
	max_size = n->stack[0];
	while (i < n->current_size)
	{
		if (n->stack[++i] > max_size)
		{
			max_size = n->stack[i];
			ret = i;
		}
	}
	return (ret);
}

void	sort_b(t_stack *a, t_stack *b)
{
	unsigned int	i;
	unsigned int	max_i;

	while (b->current_size)
	{
		max_i = i_max_size(b);
		if (max_i > b->current_size / 2)
		{
			i = 0;
			while (i < b->current_size - max_i)
			{
				p_rrb(a, b, 1, TIME);
				i++;
			}
		}
		else if (max_i)
		{
			i = 0;
			while (i < max_i)
			{
				p_rb(a, b, 1, TIME);
				i++;
			}
		}
		p_pa(a, b, 1, TIME);
	}
}