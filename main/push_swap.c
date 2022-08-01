/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:11:55 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 20:21:29 by hrolle           ###   ########.fr       */
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

int	stacks_free(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	return (0);
}

unsigned int	set_all(int ac, char **av, t_stack *a, t_stack *b)
{
	unsigned int	len;

	if (ac < 2)
		return (0);
	len = what_is_the_len(ac, av);
	if (len < 2)
		exit_error("ERROR ARG");
	set_stacks(a, b, len);
	if (ac > 2)
		strarray_to_nbrarray(a, av);
	else
		split_arg(a, av[1]);
	if (sorted_checker(a))
		return (stacks_free(a, b));
	return (len);
}

// int	main(int ac, char **av)
// {
// 	t_stack			a;
// 	t_stack			b;
// 	unsigned int	len;

// 	len = set_all(ac, av, &a, &b);
// 	if (!len)
// 		return (0);
// 	if (len == 2)
// 		if (a.stack[0] > a.stack[1])
// 			sa(&a);
// 	if (len == 3)
// 		three_sort(&a);
// 	else if (len == 4 || len == 5)
// 		five_sort(&a, &b);
// 	else if (len > 5)
// 	{
// 		while (a.current_size > 0)
// 			push_chunk(&a, &b, monmin(&a, min_size(&a),
// 					(a.current_size / 4 + 42) / 2), monmin(&a, min_size(&a),
// 					((a.current_size / 4 + 42) / 2) / 2));
// 		sort_b(&a, &b);
// 	}
// 	return (stacks_free(&a, &b));
// }

/*----------TEST-----------*/

int	main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	unsigned int	len;

	len = set_all(ac, av, &a, &b);
	if (!len)
		return (0);
	if (len == 2)
		if (a.stack[0] > a.stack[1])
			sa(&a);
	if (len == 3)
		three_sort(&a);
	else if (len == 4 || len == 5)
		five_sort(&a, &b);
	else if (len > 5)
		simple_sort(&a, &b);
	return (stacks_free(&a, &b));
}
