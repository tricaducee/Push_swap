/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:41:31 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/08 19:42:37 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	p_ra(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	rotate(a);
	if (arg->stacks)
		ft_printfd(1, "#+gRA            :#0\n");
	w_print_stacks(a, b, arg);
}

void	p_rb(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	rotate(b);
	if (arg->stacks)
		ft_printfd(1, "#+gRB            :#0\n");
	w_print_stacks(a, b, arg);
}

void	p_rr(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	rotate(a);
	rotate(b);
	if (arg->stacks)
		ft_printfd(1, "#+gRR            :#0\n");
	w_print_stacks(a, b, arg);
}
