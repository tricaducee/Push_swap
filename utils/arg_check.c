/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:23:41 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/11 04:32:31 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	arg_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!(av[i][j] <= '9' && av[i][j] >= '0'))
			return (0);
		while (av[i][j] <= '9' && av[i][j] >= '0')
			j++;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j])
			return (0);
		i++;
	}
	return (1);
}
