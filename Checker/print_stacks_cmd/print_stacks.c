/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:51:13 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/08 05:22:26 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	wait_erase(unsigned int lines, int time)
{
	unsigned int	i;

	i = 0;
	usleep(time * 1000);
	ft_printfd(1, "\r");
	while (i < lines)
	{
		ft_printfd(1, "\033[A");
		i++;
	}
}

void	prog_bar(int prog)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i < prog)
			ft_printfd(1, "#G #0");
		else
			ft_printfd(1, "#B #0");
		i++;
	}
}

void	print_percent(t_stack *n)
{
	int		percent;

	percent = ((float)n->sorted_size / (float)n->real_size) * 100;
	prog_bar(percent / 10);
	ft_printfd(1, "#/+g %3d%%#0           \n", percent);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	unsigned int	i;

	i = 0;
		ft_printfd(1, "\nA        B        \n");
	ft_printfd(1, "-        -        \n");
	while (i < a->real_size)
	{
		if (i < a->current_size)
			ft_printfd(1, "%-8d ", a->stack[i]);
		else
			ft_printfd(1, "%-8c ", ' ');
		if (i < b->current_size)
			ft_printfd(1, "%-8d \n", b->stack[i]);
		else
			ft_printfd(1, "%-8c \n", ' ');
		i++;
	}
	ft_printfd(1, "%-8c %-8c \n\n", '-', '-');
}

void	w_print_stacks(t_stack *a, t_stack *b, int yes_no, int time)
{
	unsigned int	i;

	i = 0;
		ft_printfd(1, "\n#+bA             #+pB#0          \n");
	ft_printfd(1, "-             -          \n");
	while (i < a->real_size)
	{
		if (i < a->current_size)
			ft_printfd(1, "#b%-14d#0", a->stack[i]);
		else
			ft_printfd(1, "              ");
		if (i < b->current_size)
			ft_printfd(1, "#p%-11d#0\n", b->stack[i]);
		else
			ft_printfd(1, "           \n");
		i++;
	}
	ft_printfd(1, "-             -          \n");
	print_percent(a);
	if (yes_no)
		wait_erase(a->real_size + 6, time);
}