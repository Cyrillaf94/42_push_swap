#include "push_swap.h"

void	ft_list_print(node_t *node)
{
	int	i;
	node_t*	current;

	current = node;
	i = 0;
	while (current && (i == 0 | current != node))
	{
		printf("%i\n", current->data);
		current = current->next;
		i++;
	}
}