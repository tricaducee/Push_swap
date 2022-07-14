/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:42 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 15:22:00 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	reverse_rotate(t_stack *nb)
{
	int	i;
	int	tmp;

	if (nb->current_size < 2)
		return ;
	i = nb->current_size - 1;
	tmp = nb->stack[i];
	while (i)
	{
		i--;
		nb->stack[i + 1] = nb->stack[i];
	}
	nb->stack[0] = tmp;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
