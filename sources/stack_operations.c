#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*item;

	item = (*from);
	(*from) = (*from)->next;
	item->next = (*to);
	*to = item;
}

void	swap(t_stack **stack)
{
	if (len_stack(*stack) >= 2 && (*stack)->order != (*stack)->next->order)
	{
		(*stack)->order += (*stack)->next->order;
		(*stack)->next->order = (*stack)->order - (*stack)->next->order;
		(*stack)->order -= (*stack)->next->order;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*first_el;
	t_stack	*last_el;

	if (len_stack(*stack) < 2)
		return ;
	first_el = *stack;
	*stack = first_el->next;
	last_el = (*stack);
	while (last_el->next)
		last_el = last_el->next;
	last_el->next = first_el;
	first_el->next = NULL;
}

void	rrotate(t_stack **stack)
{
	t_stack	*last_el;
	int		i;

	if (len_stack(*stack) < 2)
		return ;
	i = len_stack(*stack) - 1;
	last_el = (*stack);
	while (last_el->next)
		last_el = last_el->next;
	last_el->next = (*stack);
	(*stack) = last_el;
	last_el = (*stack);
	while (i-- > 0)
		last_el = last_el->next;
	last_el->next = NULL;
}
