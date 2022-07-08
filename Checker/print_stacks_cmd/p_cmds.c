/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:50:59 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/08 02:41:37 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void    p_pb(t_stack *a, t_stack *b, int yes_no, int time)
{
	push(a, b);
	ft_printfd(1, "#+gPB         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_pa(t_stack *a, t_stack *b, int yes_no, int time)
{
	push(b, a);
	a->sorted_size += 1;
	ft_printfd(1, "#+gPA         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_rra(t_stack *a, t_stack *b, int yes_no, int time)
{
	reverse_rotate(a);
	ft_printfd(1, "#+gRRA        :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_rrb(t_stack *a, t_stack *b, int yes_no, int time)
{
	reverse_rotate(b);
	ft_printfd(1, "#+gRRB        :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_rrr(t_stack *a, t_stack *b, int yes_no, int time)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printfd(1, "#+gRRR        :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_ra(t_stack *a, t_stack *b, int yes_no, int time)
{
	rotate(a);
	ft_printfd(1, "#+gRA         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_rb(t_stack *a, t_stack *b, int yes_no, int time)
{
	rotate(b);
	ft_printfd(1, "#+gRB         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_rr(t_stack *a, t_stack *b, int yes_no, int time)
{
	rotate(a);
	rotate(b);
	ft_printfd(1, "#+gRR         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_sa(t_stack *a, t_stack *b, int yes_no, int time)
{
	swap(a);
	ft_printfd(1, "#+gSA         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_sb(t_stack *a, t_stack *b, int yes_no, int time)
{
	swap(b);
	ft_printfd(1, "#+gSB         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void    p_ss(t_stack *a, t_stack *b, int yes_no, int time)
{
	swap(a);
	swap(b);
	ft_printfd(1, "#+gSS         :#0\n");
	w_print_stacks(a, b, yes_no, time);
}

void	p_comment(t_stack *a, t_stack *b, int yes_no, int time, char *str)
{
	ft_printfd(1, "#+g%-11.11s:#0\n", str);
	w_print_stacks(a, b, yes_no, time);
}
