/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:48:20 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/09 00:04:14 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/checker.h"

unsigned int	what_is_the_len(int ac, char **av, t_option *arg)
{
	int				len;
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

int	set_and_test(int ac, char **av, t_stack *n, t_option *arg)
{
	char			*cmd;
	unsigned int	len;

	if (ac < 2)
		return (1);
	set_option(arg);
	cmd = check_option(av, arg);
	if (cmd)
	{
		ft_printfd(1, "Invalid option : %s", cmd);
		return (1);
	}
	if (ac - arg->n_arg < 2)
		return (return_error("Error\n", 1));
	len = what_is_the_len(ac, av, arg);
	if (len < 2)
		exit_error("Error\n");
	set_stacks(&n[0], &n[1], len);
	if (ac - arg->n_arg > 2)
		strarray_to_nbrarray(&n[0], &n[1], av);
	else
		split_arg(&n[0], &n[1], av[arg->num_index]);
	return (0);
}

int	stacks_free(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack		n[2];
	t_option	arg;
	char		*cmd;

	if (set_and_test(ac, av, n, &arg))
		return (1);
	double_check(&n[0], &n[1]);
	ft_printfd(1, "\033[?25l");
	p_comment(&n[0], &n[1], &arg, "STACKS");
	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		exec_cmd(&n[0], &n[1], &arg, cmd);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	sorted_checker(&n[0], &n[1], &arg);
	ft_printfd(1, "\033[?25h");
	stacks_free(&n[0], &n[1]);
	return (0);
}
