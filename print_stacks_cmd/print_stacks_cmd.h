#ifndef PRINT_STACKS_CMD_H
# define PRINT_STACKS_CMD_H
#define TIME 100
#include "../HEADER/push_swap.h"
#include "../printfd/HEADER/ft_printfd.h"

void	print_stacks(t_stack *a, t_stack *b);
void	w_print_stacks(t_stack *a, t_stack *b, int yes_no, int time);
void    p_pb(t_stack *a, t_stack *b, int yes_no, int time);
void    p_pa(t_stack *a, t_stack *b, int yes_no, int time);
void    p_rra(t_stack *a, t_stack *b, int yes_no, int time);
void    p_rrb(t_stack *a, t_stack *b, int yes_no, int time);
void    p_rrr(t_stack *a, t_stack *b, int yes_no, int time);
void    p_ra(t_stack *a, t_stack *b, int yes_no, int time);
void    p_rb(t_stack *a, t_stack *b, int yes_no, int time);
void    p_rr(t_stack *a, t_stack *b, int yes_no, int time);
void    p_sa(t_stack *a, t_stack *b, int yes_no, int time);
void    p_sb(t_stack *a, t_stack *b, int yes_no, int time);
void    p_ss(t_stack *a, t_stack *b, int yes_no, int time);
void	p_comment(t_stack *a, t_stack *b, int yes_no, int time, char *str);

#endif