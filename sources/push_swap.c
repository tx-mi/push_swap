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

void push_swap(t_stack **stack, int *sorted_array, t_info *info)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_listOperations *operations;
	int tmp_flag;
	char *c;

	stack_a = *stack;
	stack_b = NULL;
	operations = NULL;

	init_info(&info);
	info->next = 1;
	info->max = get_max(stack_a); 
	info->mid = get_mid(info->max, info->next, 1);
	print_info(info);
	print_stacks(&stack_a, &stack_b);

	while (!sorted(stack_a))
	{
		while (has_in_a(stack_a, info->mid))
		{
			if (stack_a->order <= info->mid)
				push_b(&stack_a, &stack_b, &operations);
			else
				rotate_a(&stack_a, &operations);
			print_stacks(&stack_a, &stack_b);
			if (stack_a->order == info->next)
			{
				stack_a->fix_position = 1;
				rotate_a(&stack_a, &operations);
				info->next++;
			}
		}
		while (stack_b)
		{
			info->max = info->mid;
			info->mid = get_mid(info->max, info->next, 2);
			info->flag++;
			while (has_in_b(stack_b, info->mid))
			{
				if (stack_b->order >= info->mid || stack_b->order == info->next)
				{
					stack_b->flag += info->flag;
					push_a(&stack_b, &stack_a, &operations);
				}
				else
					rotate_b(&stack_b, &operations);
			}
			if (stack_a->order == info->next)
			{
				stack_a->fix_position = 1;
				rotate_a(&stack_a, &operations);
				info->next++;
			}
			print_info(info);
			print_stacks(&stack_a, &stack_b);
			scanf(c);
		}
		if (stack_a->flag && !stack_a->fix_position)
		{
			tmp_flag = stack_a->flag;
			while (stack_a->flag == tmp_flag && !stack_a->fix_position)
			{
				push_b(&stack_a, &stack_b, &operations);
				// print_stacks(&stack_a, &stack_b);
			}
		}
		info->max = get_max(stack_a);
		info->mid = get_mid(info->max, info->next, 1);
	}
	while (operations)
	{
		printf("%s\n", operations->operation);
		operations = operations->next;
	}
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
