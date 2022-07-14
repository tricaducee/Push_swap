/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push_chunk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 04:33:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 17:22:49 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	simple_push_chunk(t_stack *a, t_stack *b, int min_size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = a->unsorted_size;
	while (i < len)
	{
		if (a->stack[0] <= min_size)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

// unsigned int	i_next_nbr(t_stack *n, int min_size)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	j = n->current_size;
// 	while (i < n->current_size && n->stack[i] < min_size)
// 		i++;
// 	while (j > 0 && n->stack[j] < min_size)
// 		j--;
// 	if (i <= n->current_size - j)
// 		return (i);
// 	return (j);
// }

// #include <stdio.h>

// void	push_chunk(t_stack *a, t_stack *b, int min_size)
// {
// 	unsigned int	i;
// 	unsigned int	next_i;

// 	while (a->current_size)
// 	{
// 		next_i = i_next_nbr(a, min_size);
// 		if (a->stack[next_i] < min_size)
// 			return ;
// 		i = 0;
// 		if (next_i > a->current_size / 2)
// 		{
// 			while (i < a->current_size - next_i)
// 			{
// 				rra(a);
// 				i++;
// 			}
// 		}
// 		else
// 		{
// 			while (i < next_i)
// 			{
// 				ra(a);
// 				i++;
// 			}
// 		}
// 		pb(a, b);
// 	}
// }
