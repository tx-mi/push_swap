#include "push_swap.h"

t_coms	*new_command(char *command)
{
	t_coms	*res;

	res = (t_coms *)malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->com = command;
	res->next = NULL;
	return (res);

}

void	add_command(t_coms **commands, t_coms *com)
{
	t_coms	*last_el;

	last_el = (*commands);
	if (*commands)
	{
		while (last_el->next)
			last_el = last_el->next;
		last_el->next = com;
	}
	else
		*commands = com;
}

void	print_coms(t_coms **commands)
{
	t_coms	*com;

	com = *commands;
	while (com)
	{
		printf("%s\n", com->com);
		com = com->next;
	}
}
