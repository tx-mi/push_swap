#include "push_swap.h"

void	swap_a(t_stack **stack_a, t_coms **commands)
{
	t_coms	*com;

	com = new_command("sa");
	add_command(commands, com);
	swap(stack_a);

}

void	swap_b(t_stack **stack_b, t_coms **commands)
{
	t_coms	*com;

	com = new_command("sb");
	add_command(commands, com);
	swap(stack_b);
}

void	swap_s(t_stack **stack_a, t_stack **stack_b, t_coms **commands)
{
	t_coms	*com;

	com = new_command("ss");
	add_command(commands, com);
	swap(stack_a);
	swap(stack_b);
}

void	push_a(t_stack **stack_b, t_stack **stack_a, t_coms **commands)
{
	t_coms	*com;

	com = new_command("pa");
	add_command(commands, com);
	push(stack_b, stack_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_coms **commands)
{
	t_coms	*com;

	com = new_command("pb");
	add_command(commands, com);
	push(stack_a, stack_b);
}

void	rotate_a(t_stack **stack_a, t_coms **commands)
{
	t_coms	*com;

	com = new_command("ra");
	add_command(commands, com);
	rotate(stack_a);
}

void	rotate_b(t_stack **stack_b, t_coms **commands)
{
	t_coms	*com;

	com = new_command("rb");
	add_command(commands, com);
	rotate(stack_b);
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b, t_coms **commands)
{
	t_coms	*com;

	com = new_command("rr");
	add_command(commands, com);
	rotate(stack_a);
	rotate(stack_b);
}

void	rrotate_a(t_stack **stack_a, t_coms **commands)
{
	t_coms	*com;

	com = new_command("rra");
	add_command(commands, com);
	rrotate(stack_a);
}

void	rrotate_b(t_stack **stack_b, t_coms **commands)
{
	t_coms	*com;

	com = new_command("rrb");
	add_command(commands, com);
	rrotate(stack_b);
}

void	rrotate_r(t_stack **stack_a, t_stack **stack_b, t_coms **commands)
{
	t_coms	*com;

	com = new_command("rrr");
	add_command(commands, com);
	rrotate(stack_a);
	rrotate(stack_b);
}
