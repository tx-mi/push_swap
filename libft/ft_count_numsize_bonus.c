#include "libft.h"

size_t	ft_count_numsize(size_t num, int base)
{
	size_t	res;

	res = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		res++;
		num /= base;
	}
	return (res);
}
