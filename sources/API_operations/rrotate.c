#include "push_swap.h"

void	rrotate_a(t_stack **stack_a,
		t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("rra");
	add_operation(operations, command);
	rrotate(stack_a);
}

void	rrotate_b(t_stack **stack_b,
		t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("rrb");
	add_operation(operations, command);
	rrotate(stack_b);
}

void	rrotate_r(t_stack **stack_a, t_stack **stack_b,
		t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("rrr");
	add_operation(operations, command);
	rrotate(stack_a);
	rrotate(stack_b);
}
