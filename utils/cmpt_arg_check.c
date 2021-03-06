/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpt_arg_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:02:04 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/08 06:02:10 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

unsigned int	cmpt_arg_check(char *arg)
{
	int	i;

	i = 0;
	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		while (*arg && (*arg == '-' || *arg == '+'))
			arg++;
		if (*arg && (*arg > '9' || *arg < '0'))
			return (0);
		i++;
		while (*arg && (*arg <= '9' && *arg >= '0'))
			arg++;
	}
	return (i);
}
