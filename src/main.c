/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:18:16 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 18:41:53 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*list;

	list = NULL;
	list = parse_list(argc, argv);
	if (list)
	{
		ft_list_print(list, 'a');
		sort_list(list, argc - 1);
		ft_lstclear_circular(&list);
	}
	return (0);
}
