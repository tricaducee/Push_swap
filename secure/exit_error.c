/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:05 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/07 03:10:56 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	exit_error(char *str, t_stack *a, t_stack *b)
{
	if (a && a->stack)
	{
		free(a->stack);
		a->stack = NULL;
	}
	if (b && b->stack)
	{
		free(b->stack);
		b->stack = NULL;
	}
	write(2, str, ft_strlen(str));
	exit(1);
}
