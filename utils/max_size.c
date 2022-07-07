/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:43:15 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/07 01:51:53 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	max_size(t_stack *n)
{
	int	i;
	int	max_size;

	i = 1;
	max_size = n->stack[0];
	while (i < n->current_size)
	{
		if (n->stack[i] > max_size)
			max_size = n->stack[i];
	}
	return (max_size);
}