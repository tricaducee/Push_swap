/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 03:01:46 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/11 07:32:57 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/push_swap.h"

int	ft_satoi(const char *str, t_stack *a, t_stack *b)
{
	int				pn;
	long long int	nbr;

	pn = 1;
	nbr = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			pn *= -1;
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + (*(str++) - '0');
	nbr *= pn;
	if (nbr > 2147483647 || nbr < -2147483648)
		exit_error("Error\n", a, b);
	return ((int)nbr);
}
