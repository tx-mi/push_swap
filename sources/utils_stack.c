#include "push_swap.h"

t_stack	*new_item(int value)
{
	t_stack	*item;

	item = (t_stack *)malloc(sizeof(*item));
	if (!item)
		return (NULL);
	item->value = value;
	item->flag = 0;
	item->order = 0;
	item->fix_position = 0;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}

int	len_stack(t_stack *first_item)
{
	t_stack	*curr_item;
	int		length;

	if (!first_item)
		return (0);
	curr_item = first_item->next;
	length = 1;
	while (curr_item)
	{
		curr_item = curr_item->next;
		length++;
	}
	return (length);
}

void	add_back(t_stack **stack, t_stack *new_item)
{
	t_stack	*last_item;

	last_item = (*stack);
	if (*stack)
	{
		while (last_item->next)
			last_item = last_item->next;
		last_item->next = new_item;
	}
	else
		*stack = new_item;
}

void	add_to_stack(t_stack **stack, int len, char **values)
{
	int	i;

	i = 1;
	while (i < len)
		add_back(stack, new_item(ft_atoi(values[i++])));
}
