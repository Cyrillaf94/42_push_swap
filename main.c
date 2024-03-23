#include "push_swap.h"

int main(int argc, char **argv)
{

	node_t *list = parse_list(argc, argv);
	ft_list_print(list);
	ft_lstclear(&list);
	return (0);
}
