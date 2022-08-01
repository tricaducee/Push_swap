#include "../HEADER/push_swap.h"

int	find_min(t_stack *n)
{
	unsigned int i = 0;
	int min = n->stack[0];
	while (i < n->current_size)
	{
		if (n->stack[i] < min)
			min = n->stack[i];
		i++;
	}
	return (min);
}

void test_chunk(t_stack *a, t_stack *b, int pivot_a, int pivot_b)
{
	unsigned int i;

	i = 0;
	while (i < a->current_size)
	{
		if (a->stack[0] <= pivot_a)
		{
			pb(a, b);
			if (b->current_size > 1 && b->stack[0] > pivot_b)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}

unsigned int	find_max_i(t_stack *n)
{
	unsigned int	i;
	unsigned int	ret;
	int				max;

	i = 0;
	ret = 0;
	max = n->stack[0];
	while (i < n->current_size)
	{
		if (n->stack[i] > max)
		{
			ret = i;
			max = n->stack[i];
		}
		i++;
	}
	return (ret);
}

void selection_sort(t_stack *a, t_stack *b)
{
	unsigned int	i;
	unsigned int	max;

	while (b->current_size)
	{
		i = 0;
		max = find_max_i(b);
		if (max < (b->current_size - 1) / 2)
			while (i++ < max)
				rb(b);
		else
			while (i++ < b->current_size - max)
				rrb(b);
		pa(b, a);
	}
}

void simple_sort(t_stack *a, t_stack *b)
{
	int	min;
	int	div;

	while (a->current_size)
	{
		min = find_min(a);
		div = (int)((a->current_size / 4 + 42) / 2);
		test_chunk(a, b, min + div, min + (div / 2));
	}
	selection_sort(a, b);
}
