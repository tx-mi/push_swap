#include "push_swap.h"

static void	eject_num(t_stack **stack_a, int num,
				t_listOperations **operations)
{
	t_stack	*tmp_item;
	int		count;

	tmp_item = (*stack_a);
	count = 0;
	while (tmp_item->order != num)
	{
		tmp_item = tmp_item->next;
		count++;
	}
	if (5 - count >= 2)
		while (count--)
			rotate_a(stack_a, operations);
	else
	{
		count = 5 - count;
		while (count--)
			rrotate_a(stack_a, operations);
	}
}

int	is_under(t_stack **stack_a, t_info **info)
{
	t_stack	*item;
	int		flag;

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

int	last_next(t_stack **stack_b, t_stack **stack_a, t_info **info,
		t_listOperations **operations)
{
	t_stack	*last_item;
	int		len;

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

void	three_items(t_stack **stack_a, t_listOperations **operations)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->order;
	second = (*stack_a)->next->order;
	third = (*stack_a)->next->next->order;
	if (first > second && second < third && third > first)
		swap_a(stack_a, operations);
	else if (first > second && second > third && third < first)
	{
		swap_a(stack_a, operations);
		rrotate_a(stack_a, operations);
	}
	else if (first > second && second < third && third < first)
		rotate_a(stack_a, operations);
	else if (first < second && second > third && third > first)
	{
		swap_a(stack_a, operations);
		rotate_a(stack_a, operations);
	}
	else if (first < second && second > third && third < first)
		rrotate_a(stack_a, operations);
}

void	five_items(t_stack **stack_a, t_stack **stack_b,
			t_listOperations **operations)
{
	eject_num(stack_a, 1, operations);
	push_b(stack_a, stack_b, operations);
	eject_num(stack_a, 2, operations);
	push_b(stack_a, stack_b, operations);
	three_items(stack_a, operations);
	push_a(stack_b, stack_a, operations);
	push_a(stack_b, stack_a, operations);
}
