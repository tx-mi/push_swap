#include "push_swap.h"

static int	is_valid(t_stack *stack_a)
{
	// gag
	return (1);
}

static void	finish_spin(t_stack **stack_a)
{
	; // gag
}

static int	in_b(t_stack **stack_b, int el)
{
	t_stack	*item;
	int		i;

	item = *stack_b;
	i = 0;
	while (item)
	{
		if (item->element == el)
			return (1);
		item = item->next;
		i++;
	}
	return (0);
}

static int	up_element(t_stack ** stack_b, int el, t_coms **commands)
{
	int rr = 0;
	int r = 0;
	int res = 0;
	t_stack	*item = *stack_b;

	while (item)
	{
		if (item->element == el)
			break;
		item = item->next;
		r++;
	}
	while (item)
	{
		rr++;
		item = item->next;
	}
	if (rr < r)
	{
		res = rr;
		while (rr-- > 0)
			rrotate_b(stack_b, commands);
	}
	else
	{
		res = r;
		while (r-- > 0)
			rotate_b(stack_b, commands);
	}
	return (res);
}

static void up(t_stack **stack, int el)
{
	;
}

void	push_swap(t_stack *stack_a)
{
	t_coms	*commands;
	t_stack	*stack_b;
	int		length;
	int		diff_m;

	stack_b = NULL;
	commands = NULL;
	length = len_stack(stack_a);
	// print_stack(&stack_a, &stack_b);
	while (1)
	{
		if (is_sort(&stack_a) && !stack_b)
			break ;
		diff_m = diff_mod(stack_a->element, stack_a->next->element);
		if (diff_m > 1)
		{
			if (stack_a->element > stack_a->next->element)
				swap_a(&stack_a, &commands);
			push_b(&stack_a, &stack_b, &commands);
		}
		else if (stack_a->element - stack_a->next->element == 1)
			swap_a(&stack_a, &commands);
		else if (len_stack(stack_b) > 0 && in_b(&stack_b, stack_a->element - 1))
		{
			up_element(&stack_b, stack_a->element - 1, &commands);
			push_a(&stack_b, &stack_a, &commands);
		}
		else if (len_stack(stack_b) > 0 && in_b(&stack_b, stack_a->next->element - 1))
		{
			up_element(&stack_b, stack_a->next->element - 1, &commands);
			swap_a(&stack_a, &commands);
			push_a(&stack_b, &stack_a, &commands);
		}
		else
			rrotate_a(&stack_a, &commands);
		if (can_sort(&stack_a) && !stack_b)
			break ;
	}
	if (!is_sort(&stack_a))
		up_element(&stack_a, 0, &commands);
	print_coms(&commands);
	// print_stack(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = parse(argc, argv);
	if (stack_a && is_valid(stack_a) && convert_to_ind(&stack_a))
		push_swap(stack_a);
	else
	{
		write(2, "Error\n", 6);
		return (2);
	}
	return (0);
}
