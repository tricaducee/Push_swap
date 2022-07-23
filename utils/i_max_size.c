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
//#include <stdio.h>

int sec_max_size(t_stack *n, int max_size)
{
	unsigned int	i;
	int				sec_max_size;
	unsigned int	ret;

	i = 0;
	sec_max_size = -2147483648;
	while (i < n->current_size)
	{
		if (n->stack[i] < max_size && n->stack[i] > sec_max_size)
		{
			sec_max_size = n->stack[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	i_max_size(t_stack *n, unsigned int *s_check)
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
	if (!*s_check)
	{
		*s_check = 1;
		return (ret);
	}
	i = sec_max_size(n, max_size);
	if ((ret > n->current_size / 2 && i > ret)
		|| (ret < n->current_size / 2 && i < ret))
	{
		//printf("Là !\n");
		*s_check = 0;
		return (i);
	}
	return (ret);
}
