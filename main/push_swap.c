/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:11:55 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/07 01:39:100 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	up_unsorted(t_stack *a)
{
	unsigned int	i;

	i = 0;
	while (i < a->unsorted_size)
	{
		rra(a);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		size;

	if (!arg_check(av) || ac < 3)
		exit_error("ERROR ARG");
	set_stacks(&a, &b, av, ac - 1);
	while (a.unsorted_size > 0)
	{
		size = monmax(&a, max_size(&a), a.real_size / 10 + 22);
		push_chunk(&a, &b, size);
		sort_b(&a, &b);
		up_unsorted(&a);
	}
	free(a.stack);
	free(b.stack);
	return (0);
}
