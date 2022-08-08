/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:02:02 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/08 21:02:18 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

char	*check_option(char **av, t_option *arg)
{
	unsigned int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
			return (av[i]);
		if (av[i][0] == '-')
			if (av[i][1] && (av[i][1] > '9' || av[i][1] < '0'))
				if (add_option(av[i] + 1, arg))
					return (av[i]);
		i++;
	}
	return (NULL);
}
