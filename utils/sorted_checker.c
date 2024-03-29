/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:26:00 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/07 02:21:54 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	sorted_checker(t_stack *a, t_stack *b)
{
	unsigned int	i;

	i = 0;
	if (b->current_size)
		return (0);
	while (i < a->current_size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
