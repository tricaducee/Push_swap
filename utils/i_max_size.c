/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_max_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:28 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/08 22:03:47 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"
//#include <stdio.h>

int	sec_max_size(t_stack *n, int max_size)
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

void	norm_fcku(unsigned int *i, unsigned int *ret, int *max_size, t_stack *n)
{
	*max_size = n->stack[*i];
	*ret = *i;
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
		if (n->stack[++i] > max_size)
			norm_fcku(&i, &ret, &max_size, n);
	if (!*s_check)
	{
		*s_check = 1;
		return (ret);
	}
	i = sec_max_size(n, max_size);
	if ((ret > n->current_size / 2 && i > ret)
		|| (ret < n->current_size / 2 && i < ret))
	{
		*s_check = 0;
		return (i);
	}
	return (ret);
}
