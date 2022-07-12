/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:11:55 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/07 01:39:100 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

unsigned int	what_is_the_len(int ac, char **av)
{
	int	len;

	if (ac < 3)
		len = cmpt_arg_check(av[1]);
	else if (!arg_check(av))
		len = 0;
	else
		len = ac - 1;
	return (len);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	//int				size;
	unsigned int	len;

	if (ac < 2)
		return (0);
	len = what_is_the_len(ac, av);
	if (len < 2)
		exit_error("ERROR ARG");
	set_stacks(&a, &b, len);
	//len = a.real_size / 12;
	if (ac > 2)
		strarray_to_nbrarray(&a, av);
	else
		split_arg(&a, av[1]);
	if (sorted_checker(&a))
	{
		free(a.stack);
		free(b.stack);
		return (0);
	}
	if (len == 2)
	{
		if (a.stack[0] > a.stack[1])
			sa(&a);
		free(a.stack);
		free(b.stack);
		return (0);
	}
	if (len == 3)
	{
		three_sort(&a);
		free(a.stack);
		free(b.stack);
		return (0);
	}
	if (len < 6)
	{
		five_sort(&a, &b);
		free(a.stack);
		free(b.stack);
		return (0);
	}

	while (a.current_size > 0)
		push_chunk(&a, &b, monmin(&a, min_size(&a), (a.current_size / 6 + 32) / 2));
	sort_b(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}
