#include "push_swap.h"

t_listOperations *new_operation(char *operation)
{
	t_listOperations *item;

	item = (t_listOperations *)malloc(sizeof(*item));
	if (!item)
		return (NULL);
	item->operation = operation;
	item->next = NULL;
	return (item);
}

void	add_operation(t_listOperations **operations, t_listOperations *new_item)
{
	t_listOperations *last_item;

	last_item = (*operations);
	if (*operations)
	{
		// if the first item is exisist, spin last_item to the end
		while (last_item->next)
			last_item = last_item->next;
		last_item->next = new_item;
	}
	else
		*operations = new_item;
}

