/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:48:20 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/11 01:37:19 by hrolle           ###   ########.fr       */
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

unsigned int	what_is_the_len(int ac, char **av)
{
	int	len;

	if (ac < 3)
		len = cmpt_arg_check(av[1]);
	else if (!arg_check(av))
		len = 0;
	else
		len = ac - 1;
	return (len);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*cmd;
	unsigned int	len;

	if (ac < 2)
		return (0);
	len = what_is_the_len(ac, av);
	if (len < 2)
		exit_error("ERROR ARG");
	set_stacks(&a, &b, len);
	if (ac > 2)
		strarray_to_nbrarray(&a, av);
	else
		split_arg(&a, av[1]);
	p_comment(&a, &b, 1, "STACKS");
	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		exec_cmd(&a, &b, cmd);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	sorted_checker(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}
