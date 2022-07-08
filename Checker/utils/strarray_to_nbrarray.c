/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarray_to_nbrarray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:26:26 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/08 06:38:36 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	strarray_to_nbrarray(t_stack *n, char **av)
{
	unsigned int	i;

	i = 0;
	while (i < n->real_size)
	{
		n->stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
}
