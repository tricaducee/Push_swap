/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpt_arg_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:02:04 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/10 11:05:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

unsigned int	cmpt_arg_check(char *av)
{
	unsigned int	i;

	i = 0;
	if (!av)
		return (0);
	while (*av)
	{
		while (*av && *av == ' ')
			av++;
		while (*av && (*av == '-' || *av == '+'))
			av++;
		if (*av && (*av > '9' || *av < '0'))
			return (0);
		if (*av && (*av <= '9' && *av >= '0'))
			i++;
		while (*av && (*av <= '9' && *av >= '0'))
			av++;
	}
	return (i);
}
