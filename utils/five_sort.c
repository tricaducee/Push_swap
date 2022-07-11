/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:26:32 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/10 22:42:11 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	two_push(t_stack *a, t_stack *b)
{
	unsigned int	i;
	unsigned int	min_i;

	while (a->current_size - 3)
	{
		i = 0;
		min_i = i_min_size(a);
		if (min_i > a->current_size / 2)
		{
			while (i < a->current_size - min_i)
			{
				rra(a);
				i++;
			}
		}
		else
		{
			while (i < min_i)
			{
				ra(a);
				i++;
			}
		}
		pb(a, b);
	}
}

void	five_sort(t_stack *a, t_stack *b)
{
	two_push(a, b);
	if (!sorted_checker(a))
		three_sort(a);
	if (b->current_size == 2)
		pa(b, a);
	pa(b, a);
}
