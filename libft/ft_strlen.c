#include "libft.h"

size_t	ft_strlen(const char *str)
{
	char	*end_of_str;

	end_of_str = (char *)str;
	while (*end_of_str)
		end_of_str++;
	return (end_of_str - str);
}
