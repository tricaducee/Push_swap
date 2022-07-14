/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:54:48 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 15:25:14 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	monmin(t_stack *n, int min_size, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	if (len >= n->current_size)
		return (max_size(n));
	i = 0;
	tmp = 2147483647;
	while (i < len - 1)
	{
		j = 0;
		while (j < n->unsorted_size)
		{
			if (n->stack[j] <= tmp && n->stack[j] > min_size)
				tmp = n->stack[j];
			j++;
		}
		min_size = tmp;
		tmp = 2147483647;
		i++;
	}
	return (min_size);
}
