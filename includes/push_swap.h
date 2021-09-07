#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "stdio.h"
# include "libft.h"

typedef struct s_info
{
	int next;
	int mid;
	int max;
	int flag;
} t_info;

typedef struct s_stack
{
	int value;
	int order;
	int flag;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

typedef struct s_listOperations
{
	char *operation;
	struct s_listOperations *next;
} t_listOperations;

// Push-Swap
void push_swap(t_stack **stack);

// Quick sort
void quick_sort(int *array, int start, int length);

// Parse
t_stack *parse(int argc, char **argv);

// Stack control
t_stack *new_item(int value);
int len_stack(t_stack *first_item);
void add_back(t_stack **stack, t_stack *new_item);
void add_to_stack(t_stack **stack, int len, char **values);

// Stack functions
void		push(t_stack **from, t_stack **to);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		rrotate(t_stack **stack);

// Operations
void		swap_a(t_stack **stack_a, t_listOperations **commands);
void		swap_b(t_stack **stack_b, t_listOperations **commands);
void		swap_s(t_stack **stack_a, t_stack **stack_b, t_listOperations **commands);

void		push_a(t_stack **stack_b, t_stack **stack_a, t_listOperations **commands);
void		push_b(t_stack **stack_a, t_stack **stack_b, t_listOperations **commands);

void		rotate_a(t_stack **stack_a, t_listOperations **commands);
void		rotate_b(t_stack **stack_b, t_listOperations **commands);
void		rotate_r(t_stack **stack_a, t_stack **stack_b, t_listOperations **commands);

void		rrotate_a(t_stack **stack_a, t_listOperations **commands);
void		rrotate_b(t_stack **stack_b, t_listOperations **commands);
void		rrotate_r(t_stack **stack_a, t_stack **stack_b, t_listOperations **commands);

// Utils
t_listOperations *new_operation(char *operation);
void add_operation(t_listOperations **operations, t_listOperations *new_item);

#endif
