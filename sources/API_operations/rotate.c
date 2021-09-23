#include "push_swap.h"

void	rotate_a(t_stack **stack_a,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("ra");
	add_operation(operations, command);
	rotate(stack_a);
}

void	rotate_b(t_stack **stack_b,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("rb");
	add_operation(operations, command);
	rotate(stack_b);
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b,
			t_listOperations **operations)
{
	t_listOperations	*command;

	command = new_operation("rr");
	add_operation(operations, command);
	rotate(stack_a);
	rotate(stack_b);
}
