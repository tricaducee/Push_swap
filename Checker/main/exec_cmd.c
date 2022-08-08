/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:21:00 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/08 21:21:05 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	exec_cmd(t_stack *a, t_stack *b, t_option *arg, char *cmd)
{
	if (ft_strcmp(cmd, "sa\n"))
		p_sa(a, b, arg);
	else if (ft_strcmp(cmd, "sb\n"))
		p_sb(a, b, arg);
	else if (ft_strcmp(cmd, "ss\n"))
		p_ss(a, b, arg);
	else if (ft_strcmp(cmd, "pa\n"))
		p_pa(a, b, arg);
	else if (ft_strcmp(cmd, "pb\n"))
		p_pb(a, b, arg);
	else if (ft_strcmp(cmd, "ra\n"))
		p_ra(a, b, arg);
	else if (ft_strcmp(cmd, "rb\n"))
		p_rb(a, b, arg);
	else if (ft_strcmp(cmd, "rr\n"))
		p_rr(a, b, arg);
	else if (ft_strcmp(cmd, "rra\n"))
		p_rra(a, b, arg);
	else if (ft_strcmp(cmd, "rrb\n"))
		p_rrb(a, b, arg);
	else if (ft_strcmp(cmd, "rrr\n"))
		p_rrr(a, b, arg);
}
