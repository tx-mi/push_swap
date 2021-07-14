#include "push_swap.h"

static int	is_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc;
	j = 0;
	while (i-- > 1)
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (0);
	return (1);
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

static int	up_element(t_stack **stack_b, int el)
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
			rrotate_b(stack_b);
	}
	else
	{
		res = r;
		while (r-- > 0)
			rotate_b(stack_b);
	}
	return (res);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		length;
	int		diff_m;

	stack_a = NULL;
	stack_b = NULL;
	length = argc - 1;
	int count = 0;
	add_to_stack(&stack_a, argc, argv);

	// print_stack(&stack_a, &stack_b);
	while (1)
	{
		if (is_sort(&stack_a) && !stack_b)
			break ;
		diff_m = diff_mod(stack_a->element, stack_a->next->element);
		if (diff_m > 1)
		{
			if (stack_a->element > stack_a->next->element)
			{
				swap_a(&stack_a);
				count++;
			}
			push_b(&stack_a, &stack_b);
			count++;
		}
		else if (stack_a->element - stack_a->next->element == 1)
		{
			swap_a(&stack_a);
			count++;
		}
		else if (len_stack(stack_b) > 0 && in_b(&stack_b, stack_a->element - 1))
		{
			count += up_element(&stack_b, stack_a->element - 1);
			push_a(&stack_b, &stack_a);
			count++;
		}
		else if (len_stack(stack_b) > 0 && in_b(&stack_b, stack_a->next->element - 1))
		{
			count += up_element(&stack_b, stack_a->next->element - 1);
			swap_a(&stack_a);
			push_a(&stack_b, &stack_a);
			count++;
		}		
		else
		{
			rrotate_a(&stack_a);
			count++;
		}
		if (can_sort(&stack_a) && !stack_b)
			break ;
		print_stack(&stack_a, &stack_b);
	}
	print_stack(&stack_a, &stack_b);
	printf("%d\n", count);
}

int	main(int argc, char **argv)
{
	if (is_valid(argc, argv))
		push_swap(argc, argv);
	else
	{
		write(2, "Error\n", 6);
		return (2);
	}
	return (0);
}
