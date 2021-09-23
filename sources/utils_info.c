#include "push_swap.h"

void	init_info(t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	(*info)->next = 0;
	(*info)->mid = 0;
	(*info)->max = 0;
	(*info)->flag = 0;
}

int	get_mid(int max, int next, int choice)
{
	int	mid;

	if (choice == 1)
		mid = max / 2 + next;
	else
		mid = (max - next) / 2 + next;
	return (mid);
}

int	get_max(t_stack *stack_a)
{
	int	max;

	max = 0;
	while (stack_a)
	{
		if (!stack_a->fix_position && stack_a->order > max)
			max = stack_a->order;
		stack_a = stack_a->next;
	}
	return (max);
}
