#include "../HEADER/push_swap.h"

void	three_sort(t_stack *n)
{
	if (n->stack[0] > n->stack[1] && n->stack[0] > n->stack[2])
		ra(n);
	else if (n->stack[1] > n->stack[0] && n->stack[1] > n->stack[2])
		rra(n);
	if (n->stack[0] > n->stack[1])
			sa(n);
}
