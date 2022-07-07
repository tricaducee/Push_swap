/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:30:15 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/07 23:41:33 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	i_max_size(t_stack *n)
{
	unsigned int	i;
	int				max_size;
	unsigned int	ret;

	i = 0;
	ret = 0;
	max_size = n->stack[0];
	while (i < n->current_size - 1)
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
		i = 0;
		if (max_i > b->current_size / 2)
		{
			while (i < b->current_size - max_i)
			{
				rrb(b);
				i++;
			}
		}
		else if (max_i)
		{
			while (i < max_i)
			{
				rb(b);
				i++;
			}
		}
		pa(b, a);
	}
}
