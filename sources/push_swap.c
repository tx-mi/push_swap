#include "push_swap.h"

void	print_info(t_info *info)
{
	printf("-----------------------------------------------------------\n");
	printf("max: %d\n", info->max);
	printf("\n");
	printf("mid: %d\n", info->mid);
	printf("\n");
	printf("next: %d\n", info->next);
	printf("\n");
	printf("flag: %d\n", info->flag);
	printf("-----------------------------------------------------------\n");
}

void	print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*item_a;
	t_stack	*item_b;

	item_a = (*stack_a);
	item_b = (*stack_b);
	while (item_a || item_b)
	{
		if (item_a)
		{
			printf("%d\t", item_a->order);
			item_a = item_a->next;
		}
		else
			printf(" \t");
		if (item_b)
		{
			printf("%d", item_b->order);
			item_b = item_b->next;
		}
		else
			printf(" \t");
		printf("\n");
	}
	printf("_\t_\n");
	printf("a\tb\n");
	printf("-----------\n");
}

int 	has_in_a(t_stack *el, int mid)
{
	while (el)
	{
		if (el->order <= mid && !el->fix_position)
			return (1);
		el = el->next;
	}
	return (0);
}

int 	has_in_b(t_stack *el, int mid)
{
	while (el)
	{
		if (el->order >= mid)
			return (1);
		el = el->next;
	}
	return (0);
}

int	sorted(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (stack_a)
	{
		if (stack_a->order != i)
			return (0);
		i++;
		stack_a = stack_a->next;
	}
	return (1);
}

void	first_divide(t_stack **stack_a, t_stack **stack_b, t_info **info, t_listOperations **operations)
{
	(*info)->max = get_max(*stack_a); 
	(*info)->mid = get_mid((*info)->max, (*info)->next, 1);
	print_info(*info);
	print_stacks(stack_a, stack_b);
	while (has_in_a(*stack_a, (*info)->mid))
	{
		if (!(*stack_a)->fix_position && (*stack_a)->order <= (*info)->mid)
			push_b(stack_a, stack_b, operations);
		else
			rotate_a(stack_a, operations);
	}
	print_stacks(stack_a, stack_b);
}

void	second_divide(t_stack **stack_a, t_stack **stack_b, t_info **info, t_listOperations **operations)
{
	while ((*stack_b))
	{
		(*info)->max = get_max(*stack_b); 
		(*info)->mid = get_mid((*info)->max, (*info)->next, 2);
		(*info)->flag++;
		printf("mid = %d\n", (*info)->mid);
		printf("b = %p\n", *stack_b);
		while (has_in_b(*stack_b, (*info)->mid))
		{
			if ((*stack_b)->order >= (*info)->mid)
			{
				(*stack_b)->flag = (*info)->flag;
				push_a(stack_b, stack_a, operations);
			}
			else if ((*stack_b)->order == (*info)->next)
			{
				(*stack_b)->flag = (*info)->flag;
				(*stack_b)->fix_position = 1;
				(*info)->next++;
				push_a(stack_b, stack_a, operations);
				rotate_a(stack_a, operations);
			}
			else
				rotate_b(stack_b, operations);
		}
		print_stacks(stack_a, stack_b);
	}
}

int		has_orange(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->fix_position == 0 && stack_a->flag > 0)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	third_divide(t_stack **stack_a, t_stack **stack_b, t_info **info, t_listOperations **operations)
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
			push_b(stack_a, stack_b, operations);
			if ((*stack_a)->order == (*info)->next)
			{
				(*stack_a)->fix_position = 1;
				(*info)->next++;
				rotate_a(stack_a, operations);
			}
		}
		second_divide(stack_a, stack_b, info, operations);
		print_info(*info);
	}

}

void push_swap(t_stack **stack, int *sorted_array, t_info *info)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_listOperations *operations;

	stack_a = *stack;
	stack_b = NULL;
	operations = NULL;
	init_info(&info);
	info->next = 1;
	first_divide(&stack_a, &stack_b, &info, &operations);
	second_divide(&stack_a, &stack_b, &info, &operations);
	third_divide(&stack_a, &stack_b, &info, &operations);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_info *info;
	int *sorted_array;

	stack_a = parse(argc, argv);
	sorted_array = sorting_array(&stack_a);
	if (!stack_a || !sorted_array)
	{
		write(2, "Error\n", 6);
		return (2);
	}
	push_swap(&stack_a, sorted_array, info);
}
