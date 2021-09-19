#include "push_swap.h"

void	print_info(t_info *info)
{
	printf("-----------------------------------------------------------\n");
	printf("max:\n");
	printf("value = %d | order = %d\n", info->max->value, info->max->order);
	printf("\n");
	printf("mid:\n");
	printf("value = %d | order = %d\n", info->mid->value, info->mid->order);
	printf("\n");
	printf("next:\n");
	printf("value = %d | order = %d\n", info->next->value, info->next->order);
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

int 	has_in(t_stack *el, int mid)
{
	while (el)
	{
		if (el->order <= mid)
			return (1);
		el = el->next;
	}
	return (0);
}

void push_swap(t_stack **stack, int *sorted_array, t_info *info)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_listOperations *opers;

	stack_a = *stack;
	stack_b = NULL;
	opers = NULL;
	init_info(&info);
	info->max = search_element(stack_a, len_stack(stack_a));
	info->next = search_element(stack_a, 1);
	get_mid(&stack_a, 1, &info);
	print_info(info);
	print_stacks(&stack_a, &stack_b);
	while (has_in(stack_a, info->mid->order))
	{
		if (stack_a->order <= info->mid->order)
			push_b(&stack_a, &stack_b, &opers);
		else
			rotate_a(&stack_a, &opers);
		print_stacks(&stack_a, &stack_b);
	}
	while (stack_b)
	{
		info->max = info->mid;
		get_mid(&stack_b, 2, &info);
		info->flag++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_info *info;
	// t_listOperations operations;
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
