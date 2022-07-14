/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:26:00 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 15:26:01 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	sorted_checker(t_stack *n)
{
	unsigned int	i;

	i = 0;
	while (i < n->current_size - 1)
	{
		if (n->stack[i] > n->stack[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
