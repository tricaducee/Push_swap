/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarray_to_nbrarray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:26:26 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/07 03:16:47 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

void	strarray_to_nbrarray(t_stack *a, t_stack *b, char **av)
{
	unsigned int	i;

	i = 0;
	while (i < a->real_size)
	{
		a->stack[i] = ft_satoi(av[i + 1], a, b);
		i++;
	}
}
