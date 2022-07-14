/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:48:20 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 19:08:36 by hrolle           ###   ########.fr       */
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

unsigned int	what_is_the_len(int ac, char **av, t_option *arg)
{
	int	len;
	unsigned int	i;
	unsigned int	j;

	i = 1;
	if (ac - arg->n_arg < 3)
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j] && ((av[i][j] >= '0' && av[i][j] <= '9')
				|| av[i][j] == ' ' || av[i][j] == '-'))
				j++;
			if (!av[i][j])
				break ;
			i++;
		}
		arg->num_index = i;
		len = cmpt_arg_check(av[i]);
	}	
	else if (!arg_check(av))
		len = 0;
	else
		len = ac - (1 + arg->n_arg);
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

int	pcs_multi_option(char *option, t_option *arg)
{
	arg->n_arg += 1;
	while (*option)
	{
		if (*option == 'p')
			arg->percent = 1;
		else if (*option == 'c')
			arg->cmds = 1;
		else if (*option == 's')
			arg->stacks = 1;
		else
			return (1);
		option++;
	}
	return (0);
}

int	plus_option(unsigned int *n, t_option *arg, unsigned int n_add)
{
	*n = n_add;
	arg->n_arg += 1;
	return (0);
}

int	add_option(char	*option, t_option *arg)
{
	if (invalid_option(option))
		return (1);
	if (option_cmp(option, "time=") || option_cmp(option, "t="))
		return (plus_option(&arg->time, arg, option_to_i(option)));
	else if (option_cmp(option, "len=") || option_cmp(option, "l="))
		return (plus_option(&arg->top, arg, option_to_i(option)));
	else if (option_cmp(option, "percent"))
		return (plus_option(&arg->percent, arg, 1));
	else if (option_cmp(option, "cmds"))
		return (plus_option(&arg->cmds, arg, 1));
	else if (option_cmp(option, "stacks"))
		return (plus_option(&arg->stacks, arg, 1));
	else if (*option == 'p' || *option == 'c' || *option == 's')
		return (pcs_multi_option(option, arg));
	else if (option_cmp(option, "full") || option_cmp(option, "f"))
	{
		arg->stacks = 1;
		arg->percent = 1;
		arg->cmds = 1;
		arg->n_arg += 1;
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

int	main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	t_option		arg;
	char			*cmd;
	unsigned int	len;

	if (ac < 2)
		return (0);
	set_option(&arg);
	cmd = check_option(av, &arg);
	if (cmd)
	{
		ft_printfd(1, "Invalid option : %s", cmd);
		return (1);
	}
	if (ac - arg.n_arg < 2)
	{
		ft_printfd(2, "ERROR");
		return (1);
	}
	len = what_is_the_len(ac, av, &arg);
	if (len < 2)
		exit_error("ERROR ARG");
	set_stacks(&a, &b, len);
	if (ac - arg.n_arg > 2)
		strarray_to_nbrarray(&a, av);
	else
		split_arg(&a, av[arg.num_index]);
	// ft_printfd(1, "arg.time = %u\n", arg.time);
	// ft_printfd(1, "arg.top = %u\n", arg.top);
	// ft_printfd(1, "arg.percent = %u\n", arg.percent);
	// ft_printfd(1, "arg.stacks = %u\n", arg.stacks);
	// ft_printfd(1, "arg.cmds = %u\n", arg.cmds);
	// ft_printfd(1, "arg.n_arg = %u\n", arg.n_arg);
	// ft_printfd(1, "arg.num_index = %u\n", arg.num_index);
	ft_printfd(1, "\033[?25l");
	p_comment(&a, &b, &arg, "STACKS");
	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		exec_cmd(&a, &b, &arg, cmd);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	sorted_checker(&a, &b, &arg);
	ft_printfd(1, "\033[?25h");
	free(a.stack);
	free(b.stack);
	return (0);
}
