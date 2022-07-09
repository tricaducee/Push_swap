/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:54:56 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/08 02:09:30 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	print_ok(void)
{
	ft_printfd(1, "#+g\n.OKOKOK.  OK .OK  \n");
	ft_printfd(1, "OK    OK  OK KO   \n");
	ft_printfd(1, "OK    OK  OKOK    \n");
	ft_printfd(1, "OK    OK  OKOKO   \n");
	ft_printfd(1, "OK    OK  OK  OK  \n");
	ft_printfd(1, "'OKOKOK'  OK   KO.#0\n\n\n");
}

void	print_ko(void)
{
	ft_printfd(1, "#+r\nKO .KO    .KOKOKO.\n");
	ft_printfd(1, "KO OK     KO    KO\n");
	ft_printfd(1, "KOKO      KO    KO\n");
	ft_printfd(1, "KOKOK     KO    KO\n");
	ft_printfd(1, "KO  KO    KO    KO\n");
	ft_printfd(1, "KO   OK.  'KOKOKO'#0\n\n\n");
}

int	sorted_checker(t_stack *a, t_stack *b)
{
	unsigned int	i;

	i = 0;
	while (i < a->current_size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
		{
			p_comment(a, b, 0, "FAIL");
			ft_printfd(1, "\r\033[A                         \r");
			print_ko();
			return (0);
		}
		i++;
	}
	p_comment(a, b, 0, "SORTED");
	ft_printfd(1, "\r\033[A                         \r");
	print_ok();
	return (1);
}
