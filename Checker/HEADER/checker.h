/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:47:26 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/14 14:01:57 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
#define TIME 250
#define YES_NO 1
#define TOP 50
#include "get_next_line.h"
#include "../printfd/HEADER/ft_printfd.h"

typedef struct S_stack
{
	int             *stack;
	unsigned int    real_size;
	unsigned int    current_size;
	unsigned int    unsorted_size;
	unsigned int    sorted_size;
	unsigned int	cmds;
}                   t_stack;

typedef struct S_option
{
	unsigned int    top;
	unsigned int    time;
	unsigned int    cmds;
	unsigned int    percent;
	unsigned int	stacks;
	unsigned int	n_arg;
	unsigned int	num_index;
}                   t_option;

/*----------------CMD-----------------*/

void    pb(t_stack *a, t_stack *b);
void    push(t_stack *a, t_stack *b);
void    pa(t_stack *b, t_stack *a);
void    rotate(t_stack *nb);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    reverse_rotate(t_stack *nb);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void    swap(t_stack *nb);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);

/*---------------UTILS----------------*/

void	set_stacks(t_stack *a, t_stack *b, unsigned int size);
int		arg_check(char **av);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
void	exit_error(char *str);
int		sorted_checker(t_stack *a, t_stack *b, t_option *arg);
unsigned int	cmpt_arg_check(char *av);
void	split_arg(t_stack *n, char *arg);
void	strarray_to_nbrarray(t_stack *n, char **av);
void	ft_sleep(unsigned int time);
void	set_option(t_option *arg);

/*---------------PRINT----------------*/

void	print_stacks(t_stack *a, t_stack *b, unsigned int size);
void	w_print_stacks(t_stack *a, t_stack *b, t_option *arg);
void	f_print_stacks(t_stack *a, t_stack *b, t_option *arg);
void    p_pb(t_stack *a, t_stack *b, t_option *arg);
void    p_pa(t_stack *a, t_stack *b, t_option *arg);
void    p_rra(t_stack *a, t_stack *b, t_option *arg);
void    p_rrb(t_stack *a, t_stack *b, t_option *arg);
void    p_rrr(t_stack *a, t_stack *b, t_option *arg);
void    p_ra(t_stack *a, t_stack *b, t_option *arg);
void    p_rb(t_stack *a, t_stack *b, t_option *arg);
void    p_rr(t_stack *a, t_stack *b, t_option *arg);
void    p_sa(t_stack *a, t_stack *b, t_option *arg);
void    p_sb(t_stack *a, t_stack *b, t_option *arg);
void    p_ss(t_stack *a, t_stack *b, t_option *arg);
void	p_comment(t_stack *a, t_stack *b, t_option *arg, char *str);
void	p_final_comment(t_stack *a, t_stack *b, t_option *arg, char *str);

#endif