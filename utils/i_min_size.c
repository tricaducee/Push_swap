/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_min_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:36 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 15:24:38 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	i_min_size(t_stack *n)
{
	unsigned int	i;
	int				min_size;
	unsigned int	ret;

	i = 0;
	ret = 0;
	min_size = n->stack[0];
	while (i < n->current_size - 1)
	{
		if (n->stack[++i] < min_size)
		{
			min_size = n->stack[i];
			ret = i;
		}
	}
	return (ret);
}
