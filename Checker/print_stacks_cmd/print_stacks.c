/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:51:13 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/11 03:27:27 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	wait_erase(unsigned int lines, unsigned int time)
{
	unsigned int	i;

	i = 0;
	ft_sleep(time);
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
	ft_printfd(1, "#/+g %3d%%#0           ", percent);
}

void	print_stacks(t_stack *a, t_stack *b, unsigned int size)
{
	unsigned int	i;

	i = 0;
	ft_printfd(1, "\n#+bA             #+pB#0          \n");
	ft_printfd(1, "-             -          \n");
	while (i < size)
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
	ft_printfd(1, "#/b%-11ucmds#0\n\n", a->cmds);
}

void	w_print_stacks(t_stack *a, t_stack *b, int yes_no, unsigned int time)
{
	unsigned int	size;

	if (a->real_size > TOP)
		size = TOP;
	else
		size = a->real_size;
	print_stacks(a, b, size);
	print_percent(a);
	if (yes_no)
		wait_erase(size + 7, time);
}
