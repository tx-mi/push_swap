#include "push_swap.h"

int	last_next(t_stack **stack_b, t_stack **stack_a, t_info **info,
		t_listOperations **operations)
{
	t_stack	*last_item;
	int len;

	last_item = *stack_b;
	len = len_stack(*stack_b);
	if (len > 2)
	{
		while (last_item->next)
			last_item = last_item->next;
		if (last_item->order == (*info)->next)
		{
			rrotate_b(stack_b, operations);
			(*stack_b)->flag = (*info)->flag;
			(*stack_b)->fix_position = 1;
			(*info)->next++;
			push_a(stack_b, stack_a, operations);
			rotate_a(stack_a, operations);
			return (1);
		}
	}
	return (0);
}

int	under(t_stack **stack_a, t_info **info)
{
	t_stack *item;
	int flag;

	item = (*stack_a);
	flag = 0;
	while (item)
	{
		if (!flag && item->order <= (*info)->mid)
			return (0);
		else if (item->fix_position)
			flag++;
		else if (flag && item->order == (*info)->next)
			return (1);
		item = item->next;
	}
	return (0);
}

void	first_divide(t_stack **stack_a, t_stack **stack_b,
			t_info **info, t_listOperations **operations)
{
	(*info)->max = get_max(*stack_a);
	(*info)->mid = get_mid((*info)->max, (*info)->next, 1);
	while (has_in_a(*stack_a, (*info)->mid))
	{
		if (!(*stack_a)->fix_position && (*stack_a)->order <= (*info)->mid)
			push_b(stack_a, stack_b, operations);
		else if (under(stack_a, info))
			rrotate_a(stack_a, operations);
		else
			rotate_a(stack_a, operations);
	}
}

void	second_divide(t_stack **stack_a, t_stack **stack_b,
			t_info **info, t_listOperations **operations)
{
	while ((*stack_b))
	{
		(*info)->max = get_max(*stack_b);
		(*info)->mid = get_mid((*info)->max, (*info)->next, 2);
		(*info)->flag++;
		while (has_in_b(*stack_b, (*info)->mid))
		{
			if ((*stack_b)->order == (*info)->next)
			{
				(*stack_b)->flag = (*info)->flag;
				(*stack_b)->fix_position = 1;
				(*info)->next++;
				push_a(stack_b, stack_a, operations);
				rotate_a(stack_a, operations);
			}
			else if (last_next(stack_b, stack_a, info, operations))
				;
			else if ((*stack_b)->order >= (*info)->mid)
			{
				(*stack_b)->flag = (*info)->flag;
				push_a(stack_b, stack_a, operations);
			}
			else
				rotate_b(stack_b, operations);
		}
	}
}

void	third_divide(t_stack **stack_a, t_stack **stack_b,
			t_info **info, t_listOperations **operations)
{
	int	temp_flag;

	while (has_orange(*stack_a))
	{
		temp_flag = (*stack_a)->flag;
		while (!(*stack_a)->fix_position && (*stack_a)->flag == temp_flag)
		{
			if ((*stack_a)->order == (*info)->next)
			{
				(*stack_a)->fix_position = 1;
				(*stack_a)->flag = -1;
				(*info)->next++;
				rotate_a(stack_a, operations);
			}
			else
				push_b(stack_a, stack_b, operations);
		}
		second_divide(stack_a, stack_b, info, operations);
	}
}

void	push_swap(t_stack **stack)
{
	t_info				*info;
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_listOperations	*operations;

	stack_a = *stack;
	stack_b = NULL;
	operations = NULL;
	init_info(&info);
	info->next = 1;
	while (!is_sorted(stack_a))
	{
		first_divide(&stack_a, &stack_b, &info, &operations);
		second_divide(&stack_a, &stack_b, &info, &operations);
		third_divide(&stack_a, &stack_b, &info, &operations);
	}
	free_all(&stack_a, &stack_b, &info);
	print_operations(operations);
	free_operations(&operations);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*sorted_array;

	if (argc > 1)
	{
		stack_a = parse(argc, argv);
		sorted_array = sorting_array(&stack_a);
		if (!stack_a || !sorted_array)
		{
			write(2, "Error\n", 6);
			return (2);
		}
		free(sorted_array);
		push_swap(&stack_a);
	}
}
