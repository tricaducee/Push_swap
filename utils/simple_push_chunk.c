/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push_chunk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 04:33:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/11 07:33:39 by hrolle           ###   ########.fr       */
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
