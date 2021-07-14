#include "push_swap.h"

t_stack	*new_item(int element)
{
	t_stack	*res;

	res = (t_stack *)malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->element = element;
	res->next = NULL;
	return (res);
}

int	len_stack(t_stack *item)
{
	t_stack	*curr;
	int		length;

	if (!item)
		return (0);
	curr = item->next;
	length = 1;
	while (curr)
	{
		curr = curr->next;
		length++;
	}
	return (length);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_el;

	last_el = (*stack);
	if (*stack)
	{
		while (last_el->next)
			last_el = last_el->next;
		last_el->next = new;
	}
	else
		*stack = new;
}

void	add_to_stack(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		add_back(stack, new_item(ft_atoi(argv[i++])));
}

void	print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*item_a;
	t_stack	*item_b;

	item_a = (*stack_a);
	item_b = (*stack_b);
	while (item_a || item_b)
	{
		if (item_a)
		{
			printf("%d\t", item_a->element);
			item_a = item_a->next;
		}
		else
			printf(" \t");
		if (item_b)
		{
			printf("%d", item_b->element);
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
