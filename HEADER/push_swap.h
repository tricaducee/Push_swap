/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:14:03 by hrolle            #+#    #+#             */
/*   Updated: 2022/07/08 06:29:21 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct S_stack
{
	int             *stack;
	unsigned int    real_size;
	unsigned int    current_size;
	unsigned int    unsorted_size;
}                   t_stack;

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
int		max_size(t_stack *n);
int		min_size(t_stack *n);
int		monmax(t_stack *n, int max_size, unsigned int len);
void	push_chunk(t_stack *a, t_stack *b, int min_size);
unsigned int	cmpt_arg_check(char *arg);
void	split_arg(t_stack *n, char *arg);
void	sort_b(t_stack *a, t_stack *b);
void	strarray_to_nbrarray(t_stack *n, char **av);
//size_t		ft_strlen(char *str);

/*---------------SECURE----------------*/

void	exit_error(char *str);

#endif