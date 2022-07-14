/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:26:12 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 15:33:05 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	three_sort(t_stack *n)
{
	if (n->stack[0] > n->stack[1] && n->stack[0] > n->stack[2])
		ra(n);
	else if (n->stack[1] > n->stack[0] && n->stack[1] > n->stack[2])
		rra(n);
	if (n->stack[0] > n->stack[1])
		sa(n);
}
