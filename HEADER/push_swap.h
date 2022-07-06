#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct S_stack
{
    int             *stack;
    unsigned int    real_size;
    unsigned int    current_size;
	unsigned int    sorted_size;
}                   t_stack;

/*----------------CMD-----------------*/

void    push(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
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

void	set_stacks(t_stack *a, t_stack *b, char **av, unsigned int size);
int		arg_check(char **av);
int		ft_atoi(const char *str);
//size_t		ft_strlen(char *str);

/*---------------SECURE----------------*/

void	exit_error(char *str);

#endif