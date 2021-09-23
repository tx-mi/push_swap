#include "push_swap.h"

void	swap_a(t_stack **stack_a,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("sa");
	add_operation(operations, command);
	swap(stack_a);
}

void	swap_b(t_stack **stack_b,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("sb");
	add_operation(operations, command);
	swap(stack_b);
}

void	swap_s(t_stack **stack_a, t_stack **stack_b,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("ss");
	add_operation(operations, command);
	swap(stack_a);
	swap(stack_b);
}

void	push_a(t_stack **stack_b, t_stack **stack_a,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("pa");
	add_operation(operations, command);
	push(stack_b, stack_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("pb");
	add_operation(operations, command);
	push(stack_a, stack_b);
}
