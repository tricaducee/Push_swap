/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:41:34 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/08 19:43:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	p_sa(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	swap(a);
	if (arg->stacks)
		ft_printfd(1, "#+gSA            :#0\n");
	w_print_stacks(a, b, arg);
}

void	p_sb(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	swap(b);
	if (arg->stacks)
		ft_printfd(1, "#+gSB            :#0\n");
	w_print_stacks(a, b, arg);
}

void	p_ss(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	swap(a);
	swap(b);
	if (arg->stacks)
		ft_printfd(1, "#+gSS            :#0\n");
	w_print_stacks(a, b, arg);
}
