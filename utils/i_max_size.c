/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_max_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:28 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 15:24:30 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	i_max_size(t_stack *n)
{
	unsigned int	i;
	int				max_size;
	unsigned int	ret;

	i = 0;
	ret = 0;
	max_size = n->stack[0];
	while (i < n->current_size - 1)
	{
		if (n->stack[++i] > max_size)
		{
			max_size = n->stack[i];
			ret = i;
		}
	}
	return (ret);
}
