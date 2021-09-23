#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "stdio.h"
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				order;
	int				flag;
	int				fix_position;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_info
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}		t_info;

typedef struct s_listOperations
{
	char					*operation;
	struct s_listOperations	*next;
}							t_listOperations;

// Push-Swap
void				push_swap(t_stack **stack);

// Quick sort
void				quick_sort(int *array, int start, int length);

// Sorting array
int					*sorting_array(t_stack **stack);

// Parse
t_stack				*parse(int argc, char **argv);

// Stack functions
void				push(t_stack **from, t_stack **to);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				rrotate(t_stack **stack);

// Utils
void				init_info(t_info **info);
int					get_mid(int max, int next, int choice);
int					get_max(t_stack *stack_a);

t_listOperations	*new_operation(char *operation);
void				add_operation(t_listOperations **operations,
						t_listOperations *new_item);

int					has_in_a(t_stack *el, int mid);
int					has_in_b(t_stack *el, int mid);
int					has_orange(t_stack *stack_a);
int					is_sorted(t_stack *stack_a);

t_stack				*new_item(int value);
int					len_stack(t_stack *first_item);
void				add_back(t_stack **stack, t_stack *new_item);
void				add_to_stack(t_stack **stack, int len, char **values);
void				print_stack(t_stack *first_item);
void				free_all(t_stack **stack_a, t_stack **stack_b,
						t_info **info);

// Out put
void				print_operations(t_listOperations *operations);
void				free_operations(t_listOperations **operations);

// API Operations
void				swap_a(t_stack **stack_a, t_listOperations **commands);
void				swap_b(t_stack **stack_b, t_listOperations **commands);
void				swap_s(t_stack **stack_a, t_stack **stack_b,
						t_listOperations **commands);

void				push_a(t_stack **stack_b, t_stack **stack_a,
						t_listOperations **commands);
void				push_b(t_stack **stack_a, t_stack **stack_b,
						t_listOperations **commands);

void				rotate_a(t_stack **stack_a, t_listOperations **commands);
void				rotate_b(t_stack **stack_b, t_listOperations **commands);
void				rotate_r(t_stack **stack_a, t_stack **stack_b,
						t_listOperations **commands);

void				rrotate_a(t_stack **stack_a, t_listOperations **commands);
void				rrotate_b(t_stack **stack_b, t_listOperations **commands);
void				rrotate_r(t_stack **stack_a, t_stack **stack_b,
						t_listOperations **commands);
#endif
