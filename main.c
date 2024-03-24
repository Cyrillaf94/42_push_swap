#include "push_swap.h"

int main(int argc, char **argv)
{

	node_t *list = parse_list(argc, argv);
	ft_list_print(list);
	write(1, "\n", 1);
	ft_swap(&list);
	ft_list_print(list);
	write(1, "\n", 1);
	list = ft_rotate(&list);
	ft_list_print(list);
	write(1, "\n", 1);
	ft_swap(&list);
	ft_list_print(list);
	write(1, "\n", 1);
	node_t *list2 = parse_list(0, NULL);
	ft_push(&list, &list2);
	ft_list_print(list);
	write(1, "\n", 1);
	ft_list_print(list2);
	write(1, "\n", 1);
	ft_lstclear(&list);
	ft_lstclear(&list2);
	return (0);
}
