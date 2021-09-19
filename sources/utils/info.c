#include "push_swap.h"

t_stack *search_element(t_stack *first_item, int order)
{
	t_stack *element;

	element = first_item;
	while (element->order != order)
		element = element->next;
	if (element->order == order)
		return (element);
	return (NULL);
}

void	init_info(t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	(*info)->next = NULL;
	(*info)->mid = NULL;
	(*info)->max = NULL;
	(*info)->flag = 0;
}

void	get_mid(t_stack **stack, int choice, t_info **info)
{
	int mid;

	if (choice == 1)
		mid = (*info)->max->order / 2 + (*info)->next->order;
	else
		mid = ((*info)->max->order - (*info)->next->order) / 2 + (*info)->next->order;
	(*info)->mid = search_element(*stack, mid);
}
