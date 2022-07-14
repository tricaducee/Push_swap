/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:43:15 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 15:29:26 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	max_size(t_stack *n)
{
	unsigned int	i;
	int				max_size;

	i = 0;
	max_size = n->stack[0];
	while (i < n->unsorted_size - 1)
	{
		if (n->stack[++i] > max_size)
			max_size = n->stack[i];
	}
	return (max_size);
}
