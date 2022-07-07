/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:11:55 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/07 01:39:10 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"
#include "../printfd/HEADER/ft_printfd.h"

void	wait_erase(unsigned int lines, int time)
{
	int	i;

	i = 0;
	usleep(time * 1000);
	ft_printfd(1, "\r");
	while (i < lines)
	{
		ft_printfd(1, "\033[A");
		i++;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

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
	int	i;

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
	if (yes_no)
		wait_erase(a->real_size + 6, time);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (!arg_check(av) || ac < 3)
		exit_error("ERROR ARG");
	set_stacks(&a, &b, av, ac - 1);
	w_print_stacks(&a, &b, 1, 500);
	for (int i = 0; i < 10; i++)
	{
		ra(&a);
		w_print_stacks(&a, &b, 1, 500);
	}
	w_print_stacks(&a, &b, 0, 0);
	return (0);
}