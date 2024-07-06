/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:54 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 20:54:57 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "libftprintf.h"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef enum e_bool{
	false,
	true
}	t_bool;

typedef struct node {
	int			data;
	struct node	*next;
	struct node	*prev;
}	t_node;

typedef struct move {
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_move;

// Parsing
t_node	*parse_list(int argc, char	**argv);

// List
t_node	*remove_node(t_node **head);
void	insert_node_tail(t_node **head, t_node *new_node);
t_node	*create_node(int data);
void	ft_lstclear_circular(t_node **head);
int		ft_list_size(t_node *node);
void	ft_list_print(const t_node *node, char c);
int		find_max(t_node *head);
int		find_min(t_node *head);
t_node	*parse_list(int argc, char	**argv);

// Instructions
void	ft_push(t_node **list_from, t_node **list_to, char c);
t_node	*ft_swap(t_node **head);
t_node	*ft_rotate(t_node **head);
t_node	*ft_reverse_rotate(t_node **head);
void	ft_instruct(t_node **a, t_node **b, t_node *(instruction)(t_node **));

// Sorting
t_move	iter_list(t_node *a, t_node *b, int (*find_index)(t_node *, int));
int		find_index_dec(t_node *head, int value);
int		find_index_inc(t_node *head, int value);
void	rr_list(t_move moves, t_node **list_from, t_node **list_to, char c);
void	r_list(t_move moves, t_node **list_from, t_node **list_to, char c);
t_bool	is_sorted(t_node *head);
void	sort_list(t_node *head, int list_size);

#endif