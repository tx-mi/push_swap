#include "push_swap.h"

static int check_on_letters(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && !ft_atoi(&argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack *parse(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	stack_a = NULL;
	if (check_on_letters(argv, argc))
		return (NULL);
	i = 1;
	j = 0;
	if (argc > 2)
		while (i < argc) // Parse without quotes
			add_back(&stack_a, new_item(ft_atoi(argv[i++])));
	else if (argc == 2) // Parse with quotes
		while (argv[i][j])
		{
			add_back(&stack_a, new_item(ft_atoi(&(argv[i][j]))));
			while (argv[i][j] && argv[i][j++] != ' ')
				;
		}
	return (stack_a);
}
