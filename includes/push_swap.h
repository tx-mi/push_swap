#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "stdio.h"
# include "libft.h"

typedef struct s_stack
{
	int				element;
	struct s_stack	*next;
}					t_stack;

void		push_swap(int argc, char **argv);

// Commands
void		push(t_stack **from, t_stack **to);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		rrotate(t_stack **stack);

// Utils
t_stack		*new_item(int element);
void		add_to_stack(t_stack **stack, int argc, char **argv);
void		add_back(t_stack **stack, t_stack *new);
int			len_stack(t_stack *item);
void		print_stack(t_stack **stack_a, t_stack **stack_b);

int			diff_mod(int a, int b);
int			is_sort(t_stack **stack);
int			can_sort(t_stack **stack);

// Operations
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_s(t_stack **stack_a, t_stack **stack_b);

void		push_a(t_stack **stack_b, t_stack **stack_a);
void		push_b(t_stack **stack_a, t_stack **stack_b);

void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_r(t_stack **stack_a, t_stack **stack_b);

void		rrotate_a(t_stack **stack_a);
void		rrotate_b(t_stack **stack_b);
void		rrotate_r(t_stack **stack_a, t_stack **stack_b);

#endif
