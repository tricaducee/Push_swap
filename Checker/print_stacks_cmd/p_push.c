/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:41:23 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/08 19:41:56 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	p_pb(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	push(a, b);
	if (arg->stacks)
		ft_printfd(1, "#+gPB            :#0\n");
	w_print_stacks(a, b, arg);
}

void	p_pa(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	push(b, a);
	a->sorted_size += 1;
	a->unsorted_size -= 1;
	if (arg->stacks)
		ft_printfd(1, "#+gPA            :#0\n");
	w_print_stacks(a, b, arg);
}
