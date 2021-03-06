#include "push_swap.h"

int	has_in_a(t_stack *el, int mid)
{
	while (el)
	{
		if (el->order <= mid && !el->fix_position)
			return (1);
		el = el->next;
	}
	return (0);
}

int	has_in_b(t_stack *el, int mid)
{
	while (el)
	{
		if (el->order >= mid)
			return (1);
		el = el->next;
	}
	return (0);
}

int	has_orange(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->fix_position == 0 && stack_a->flag > 0)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack_a)
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

void	free_all(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*tmp;

	while ((*stack_a))
	{
		tmp = (*stack_a);
		free(tmp);
		(*stack_a) = (*stack_a)->next;
	}
	while ((*stack_b))
	{
		tmp = (*stack_b);
		free(tmp);
		(*stack_b) = (*stack_b)->next;
	}
	free(*info);
}
