/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:47 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/11 07:33:28 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	set_stacks(t_stack *a, t_stack *b, unsigned int size)
{
	unsigned int	i;

	i = 0;
	a->real_size = size;
	a->current_size = size;
	a->unsorted_size = size;
	b->real_size = size;
	b->current_size = 0;
	b->unsorted_size = 0;
	b->stack = NULL;
	a->stack = malloc(size * sizeof(int));
	if (!a->stack)
		exit_error("Error : malloc failure\n", a, b);
	b->stack = malloc(size * sizeof(int));
	if (!b->stack)
		exit_error("Error : malloc failure\n", a, b);
}
