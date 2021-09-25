#include "push_swap.h"

static int	check_rr(char *s1, char *s2)
{
	if ((s2 && !ft_strncmp(s1, "ra", 2) && !ft_strncmp(s2, "rb", 2))
		|| (!ft_strncmp(s1, "rb", 2) && !ft_strncmp(s2, "ra", 2)))
	{
		printf("rr\n");
		return (1);
	}
	return (0);
}

void	free_operations(t_listOperations **operations)
{
	t_listOperations	*tmp;

	while ((*operations))
	{
		tmp = *operations;
		free(tmp);
		*operations = (*operations)->next;
	}
}

void	print_operations(t_listOperations *operations)
{
	char	*s1;
	char	*s2;

	while (operations && operations->next)
	{
		s1 = operations->operation;
		s2 = operations->next->operation;
		if (check_rr(s1, s2))
			operations = operations->next;
		else if ((s2 && !ft_strncmp(s1, "pa", 2) && !(ft_strncmp(s2, "pb", 2)))
			|| (!ft_strncmp(s1, "pb", 2) && !(ft_strncmp(s2, "pa", 2))))
			operations = operations->next;
		else if ((s2 && !ft_strncmp(s1, "rra", 3) && !(ft_strncmp(s2, "rrb", 3)))
			|| (!ft_strncmp(s1, "rrb", 3) && !(ft_strncmp(s2, "rra", 3))))
		{
			printf("rrr");
			operations = operations->next;
		}
		else
			printf("%s\n", operations->operation);
		operations = operations->next;
	}
	if (operations)
		printf("%s\n", operations->operation);
}
