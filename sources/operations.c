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
