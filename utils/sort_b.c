/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:30:15 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 20:21:44 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"
//#include <stdio.h>

void	sort_b(t_stack *a, t_stack *b)
{
	unsigned int	i;
	unsigned int	s_check;
	unsigned int	max_i;

	s_check = 1;
	while (b->current_size)
	{
		//printf("s_check = %u\n", s_check);
		max_i = i_max_size(b, &s_check);
		i = 0;
		if (max_i == 1)
			sb(b);
		else if (max_i > b->current_size / 2)
			while (i++ < b->current_size - max_i)
				rrb(b);
		else
			while (i++ < max_i)
				rb(b);
		pa(b, a);
		if ((a->current_size > 1 && a->stack[0] > a->stack[1])
			&& (b->current_size > 1 && b->stack[0] < b->stack[1]))
			ss(a, b);
		else if (a->current_size > 1 && a->stack[0] > a->stack[1])
			sa(a);
	}
}
