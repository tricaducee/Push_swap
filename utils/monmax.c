/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:54:48 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/07 02:58:50 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../print_stacks_cmd/print_stacks_cmd.h"

int	monmax(t_stack *n, int max_size, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	if (len >= n->unsorted_size)
		return (min_size(n));
	i = 0;
	tmp = -2147483648;
	//ft_printfd(1, "%d\n", n->unsorted_size);
	//ft_printfd(1, "%d\n", max_size);
	while (i < len - 1)
	{
		j = 0;
		while (j < n->unsorted_size)
		{
			if (n->stack[j] >= tmp && n->stack[j] < max_size)
				tmp = n->stack[j];
			j++;
		}
		max_size = tmp;
		tmp = -2147483648;
		i++;
	}
	return (max_size);
}