#include "push_swap.h"

static void	set_indexes(t_stack **stack, int *array)
{
	t_stack	*item;
	int		i;

	item = *stack;
	i = 0;
	while (item)
	{
		while (array[i++] != item->value)
			;
		item->order = i;
		item = item->next;
		i = 0;
	}
}

static int	has_duplicates(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*sorting_array(t_stack **stack)
{
	t_stack	*item;
	int		*array;
	int		len;
	int		i;

	i = 0;
	item = *stack;
	len = len_stack(item);
	array = (int *)malloc((len + 1) * sizeof(int));
	if (!array)
		return (NULL);
	while (i < len && item)
	{
		array[i] = item->value;
		item = item->next;
		i++;
	}
	array[i] = '\0';
	quick_sort(array, 0, len);
	if (has_duplicates(array, len))
		return (NULL);
	set_indexes(stack, array);
	return (array);
}
