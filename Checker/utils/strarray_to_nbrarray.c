/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarray_to_nbrarray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:26:26 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 12:36:25 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	strarray_to_nbrarray(t_stack *n, char **av)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		if ((av[i][0] >= '0' && av[i][0] <= '9')
			|| (av[i][0] == '-' && (av[i][1] >= '0' && av[i][1] <= '9')))
			n->stack[j++] = ft_atoi(av[i]);
		i++;
	}
}
