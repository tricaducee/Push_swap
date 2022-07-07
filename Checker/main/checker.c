/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:48:20 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/07 21:43:48 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

void	exec_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strcmp(cmd, "sa\n"))
		p_sa(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "sb\n"))
		p_sb(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "ss\n"))
		p_ss(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "pa\n"))
		p_pa(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "pb\n"))
		p_pb(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "ra\n"))
		p_ra(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "rb\n"))
		p_rb(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "rr\n"))
		p_rr(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "rra\n"))
		p_rra(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "rrb\n"))
		p_rrb(a, b, YES_NO, TIME);
	else if (ft_strcmp(cmd, "rrr\n"))
		p_rrr(a, b, YES_NO, TIME);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*cmd;

	if (!arg_check(av) || ac < 3)
		exit_error("ERROR ARG");
	set_stacks(&a, &b, av, ac - 1);
	p_comment(&a, &b, 1, TIME, "STACKS");
	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		exec_cmd(&a, &b, cmd);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	p_comment(&a, &b, 0, 0, "END");
	free(a.stack);
	free(b.stack);
	return (0);
}
