/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:47:19 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/09 20:48:44 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

unsigned int	i_next_nbr_min(t_stack *n, int max_size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = n->current_size;
	while (i < n->current_size && n->stack[i] > max_size)
		i++;
	while (j > 0 && n->stack[j] > max_size)
		j--;
	if (i <= n->current_size - j)
		return (i);
	return (j);
}

void	push_chunk_min(t_stack *a, t_stack *b, int max_size)
{
	unsigned int	i;
	unsigned int	next_i;

	while (a->current_size)
	{
		next_i = i_next_nbr_min(a, max_size);
		if (a->stack[next_i] > max_size)
			return ;
		i = 0;
		if (next_i > a->current_size / 2)
		{
			while (i < a->current_size - next_i)
			{
				rra(a);
				i++;
			}
		}
		else
		{
			while (i < next_i)
			{
				ra(a);
				i++;
			}
		}
		pb(a, b);
	}
}
