#include "push_swap.h"

static void int_swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a += *b;
		*b = *a - *b;
		*a -= *b;
	}
}

static int partition(int **array, int start, int length)
{
	int pivot = (*array)[start];
	int i = start + 1;
	int j = i;

	while (j < length)
	{
		if ((*array)[j] < pivot)
		{
			int_swap(&((*array)[i]), &((*array)[j]));
			i++;
		}
		j++;
	}
	int_swap(&((*array)[start]), &((*array)[i - 1]));
	return (i - 1);
}

static void quick_sort(int *array, int start, int length)
{
	if (length > start)
	{
		int pivot_index = partition(&array, start, length);
		quick_sort(array, start, pivot_index);
		quick_sort(array, pivot_index + 1, length);
	}
}

static void	set_ind(t_stack **stack_a, int el, int ind)
{
	t_stack *tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->element == el)
			tmp->element = ind;
		tmp = tmp->next;
	}
}

static int	has_duplicates(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	convert_to_ind(t_stack **stack_a)
{
	t_stack	*el;
	int	*arr;
	int	len;
	int i;

	i = 0;
	el = *stack_a;
	len = len_stack(*stack_a);
	arr = (int *)malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (0);
	while (el)
	{
		arr[i++] = el->element;
		el = el->next;
	}
	arr[i] = '\0';
	quick_sort(arr, 0, len);
	if (has_duplicates(arr, len))
		return (0);
	i = 0;
	el = *stack_a;
	while (i < len)
	{
		set_ind(stack_a, arr[i], i);
		i++;
	}
	free(arr);
	arr = NULL;
	return (1);
}
