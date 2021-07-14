#include "push_swap.h"

int	diff_mod(int a, int b)
{
	int	diff;

	diff = a - b;
	if (diff < 0)
		diff *= -1;
	return (diff);
}

int	is_sort(t_stack **stack)
{
	t_stack	*item;

	item = (*stack);
	if (len_stack(*stack) <= 2)
		return (1);
	while (item->next)
	{
		if (item->element - item->next->element != -1)
			return (0);
		item = item->next;
	}
	return (1);
}

int	can_sort(t_stack **stack)
{
	t_stack	*item;

	item = (*stack);
	if (len_stack(*stack) <= 2)
		return (1);
	while (item->next)
	{
		if (diff_mod(item->element, item->next->element) != 1)
			return (0);
		item = item->next;
	}
	return (1);
}
