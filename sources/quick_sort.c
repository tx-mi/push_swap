#include "push_swap.h"

static void	int_swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a += *b;
		*b = *a - *b;
		*a -= *b;
	}
}

static int	partition(int **array, int start, int length)
{
	int	pivot;
	int	i;
	int	j;

	pivot = (*array)[start];
	i = start + 1;
	j = i;
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

void	quick_sort(int *array, int start, int length)
{
	int	pivot_index;

	if (length > start)
	{
		pivot_index = partition(&array, start, length);
		quick_sort(array, start, pivot_index);
		quick_sort(array, pivot_index + 1, length);
	}
}
