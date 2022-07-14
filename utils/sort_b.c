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

void	sort_b(t_stack *a, t_stack *b)
{
	unsigned int	i;
	unsigned int	max_i;

	while (b->current_size)
	{
		max_i = i_max_size(b);
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
	}
}
