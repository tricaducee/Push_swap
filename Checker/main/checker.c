/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:48:20 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/12 12:00:49 by hrolle           ###   ########.fr       */
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

int	option_cmp(char *a, char *b)
{
	while (*a && *b && *a != '=' && *b != '=' && *a == *b)
	{
		a++;
		b++;
	}
	if (*a != *b)
		return (0);
	return (1);
}

int	invalid_option(char *option)
{
	if (!*option)
		return (1);
	while (*option && *option != '=' && (*option > '9' || *option < '0'))
		option++;
	if (*option && *option == '=')
	{
		option++;
		if (!*option)
			return (1);
		while (*option && (*option <= '9' && *option >= '0'))
			option++;
	}
	if (!*option)
		return (0);
	return (1);
}

unsigned int	option_to_i(char *str)
{
	unsigned int	nbr;

	nbr = 0;
	while (*str && (*str > '9' || *str < '0'))
		str++;
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + (*(str++) - '0');
	return (nbr);
}

int	add_option(char	*option, t_option *arg)
{
	if (invalid_option(option))
		return (1);
	if (option_cmp(option, "time=") || option_cmp(option, "t="))
	{
		arg->time = option_to_i(option);
		ft_printfd(1, "time\n");
		return (0);
	}
	else if (option_cmp(option, "len=") || option_cmp(option, "l="))
	{
		arg->top = option_to_i(option);
			ft_printfd(1, "top\n");
		return (0);
	}
	else if (option_cmp(option, "percent") || option_cmp(option, "p"))
	{
		arg->percent = 1;
		return (0);
	}
	else if (option_cmp(option, "cmds") || option_cmp(option, "c"))
	{
		arg->cmds = 1;
		return (0);
	}
	else if (option_cmp(option, "full") || option_cmp(option, "f"))
	{
		arg->full = 1;
		return (0);
	}
	return (1);
}

char	*check_option(char **av, t_option *arg)
{
	unsigned int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
			if (av[i][1] && (av[i][1] > '9' || av[i][1] < '0'))
				if (add_option(av[i] + 1, arg))
					return (av[i]);
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	// t_stack			a;
	// t_stack			b;
	t_option		arg;
	char			*cmd;
	//unsigned int	len;

	if (ac < 1)
		return (0);
	set_option(&arg);
	cmd = check_option(av, &arg);
	if (cmd)
	{
		ft_printfd(2, "Invalid option : %s", cmd);
		return (1);
	}
	ft_printfd(1, "arg.time = %u\n", arg.time);
	ft_printfd(1, "arg.top = %u\n", arg.top);
	ft_printfd(1, "arg.full = %u\n", arg.full);
	ft_printfd(1, "arg.percent = %u\n", arg.percent);
	ft_printfd(1, "arg.cmds = %u\n", arg.cmds);
	//if (ac > 2)
	//{
	//	cmd = check_option(ac, av, &arg);
	//	if (cmd)
	//	{
	//		ft_printfd(1, "Invalid option : %s", cmd);
	//		return (0);
	//	}
	//}
	//len = what_is_the_len(ac, av);
	//if (len < 2)
	//	exit_error("ERROR ARG");
	//set_stacks(&a, &b, len);
	//if (ac > 2)
	//	strarray_to_nbrarray(&a, av);
	//else
	//	split_arg(&a, av[1]);
	//ft_printfd(1, "\033[?25l");
	//p_comment(&a, &b, 1, "STACKS");
	//cmd = get_next_line(STDIN_FILENO);
	//while (cmd)
	//{
	//	exec_cmd(&a, &b, cmd);
	//	free(cmd);
	//	cmd = get_next_line(STDIN_FILENO);
	//}
	//sorted_checker(&a, &b);
	//ft_printfd(1, "\033[?25h");
	//free(a.stack);
	//free(b.stack);
	return (0);
}
