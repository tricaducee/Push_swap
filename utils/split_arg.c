/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:36:30 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/10 11:48:18 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	split_arg(t_stack *a, t_stack *b, char *arg)
{
	int	i;

	i = 0;
	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		if (*arg)
			a->stack[i++] = ft_satoi(arg, a, b);
		while (*arg && *arg != ' ')
			arg++;
	}
}
