#include "../HEADER/push_swap.h"

void    push(t_stack *a, t_stack *b)
{
	int    i;

	if (!a->current_size)
		return ;
	if (b->current_size)
	{
		i = b->current_size;
		while (i)
		{
			i--;
			b->stack[i + 1] = b->stack[i];
		}
	}
	b->stack[0] = a->stack[0];
	b->current_size += 1;
	i = 0;
	while (i < a->current_size)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->current_size -= 1;
	a->unsorted_size -= 1;
}

void    pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void    pa(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pa\n", 3);
}
