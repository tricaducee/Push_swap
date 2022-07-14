/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:50:59 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 14:01:14 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void    p_pb(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	push(a, b);
	if (arg->stacks)
		ft_printfd(1, "#+gPB            :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_pa(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	push(b, a);
	a->sorted_size += 1;
	a->unsorted_size -= 1;
	if (arg->stacks)
		ft_printfd(1, "#+gPA            :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_rra(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	reverse_rotate(a);
	if (arg->stacks)
		ft_printfd(1, "#+gRRA           :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_rrb(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	reverse_rotate(b);
	if (arg->stacks)
		ft_printfd(1, "#+gRRB           :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_rrr(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	reverse_rotate(a);
	reverse_rotate(b);
	if (arg->stacks)
		ft_printfd(1, "#+gRRR           :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_ra(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	rotate(a);
	if (arg->stacks)
		ft_printfd(1, "#+gRA            :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_rb(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	rotate(b);
		if (arg->stacks)
	ft_printfd(1, "#+gRB            :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_rr(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	rotate(a);
	rotate(b);
		if (arg->stacks)
	ft_printfd(1, "#+gRR            :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_sa(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	swap(a);
		if (arg->stacks)
	ft_printfd(1, "#+gSA            :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_sb(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	swap(b);
		if (arg->stacks)
	ft_printfd(1, "#+gSB            :#0\n");
	w_print_stacks(a, b, arg);
}

void    p_ss(t_stack *a, t_stack *b, t_option *arg)
{
	a->cmds += 1;
	swap(a);
	swap(b);
	if (arg->stacks)
		ft_printfd(1, "#+gSS            :#0\n");
	w_print_stacks(a, b, arg);
}

void	p_comment(t_stack *a, t_stack *b, t_option *arg, char *str)
{
	if (arg->stacks)
		ft_printfd(1, "#+g%-14.14s:#0\n", str);
	w_print_stacks(a, b, arg);
}

void	p_final_comment(t_stack *a, t_stack *b, t_option *arg, char *str)
{
	if (arg->stacks)
		ft_printfd(1, "#+g%-14.14s:#0\n", str);
	f_print_stacks(a, b, arg);
}