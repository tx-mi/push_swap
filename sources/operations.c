#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	rrotate_a(t_stack **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_stack **stack_b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
}
