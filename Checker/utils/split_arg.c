/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:36:30 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/08 17:41:34 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	split_arg(t_stack *a, t_stack *b, char *arg)
{
	int	i;

	i = 0;
	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		a->stack[i++] = ft_satoi(arg, a, b);
		while (*arg && *arg != ' ')
			arg++;
	}
}
