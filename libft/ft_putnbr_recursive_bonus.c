#include "libft.h"

void	ft_putnbr_recursive(size_t num)
{
	size_t	number;

	number = '0';
	if (num / 10 == 0)
	{
		number += num;
		write(1, &number, 1);
	}
	else
	{
		ft_putnbr_recursive(num / 10);
		ft_putnbr_recursive(num % 10);
	}
}
