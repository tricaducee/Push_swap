#include "../HEADER/push_swap.h"
#include "../printfd/HEADER/ft_printfd.h"

void	wait_erase(unsigned int lines, int time)
{
	int	i;

	i = 0;
	usleep(time * 1000);
	ft_printfd(1, "\r");
	while (i < lines)
	{
		ft_printfd(1, "\033[A");
		i++;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
		ft_printfd(1, "\nA        B        \n");
	ft_printfd(1, "-        -        \n");
	while (i < a->real_size)
	{
		if (i < a->current_size)
			ft_printfd(1, "%-8d ", a->stack[i]);
		else
			ft_printfd(1, "%-8c ", ' ');
		if (i < b->current_size)
			ft_printfd(1, "%-8d \n", b->stack[i]);
		else
			ft_printfd(1, "%-8c \n", ' ');
		i++;
	}
	ft_printfd(1, "%-8c %-8c \n\n", '-', '-');
}

void	w_print_stacks(t_stack *a, t_stack *b, int yes_no, int time)
{
	int	i;

	i = 0;
		ft_printfd(1, "\nA        B        \n");
	ft_printfd(1, "-        -        \n");
	while (i < a->real_size)
	{
		if (i < a->current_size)
			ft_printfd(1, "%-8d ", a->stack[i]);
		else
			ft_printfd(1, "%-8c ", ' ');
		if (i < b->current_size)
			ft_printfd(1, "%-8d \n", b->stack[i]);
		else
			ft_printfd(1, "%-8c \n", ' ');
		i++;
	}
	ft_printfd(1, "%-8c %-8c \n\n", '-', '-');
	if (yes_no)
		wait_erase(a->real_size + 4, time);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (!arg_check(av) || ac < 3)
		exit_error("ERROR ARG");
	set_stacks(&a, &b, av, ac - 1);
	
	return (0);
}