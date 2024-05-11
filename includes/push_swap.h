/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:54 by cyril             #+#    #+#             */
/*   Updated: 2024/05/11 09:35:28 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>  // For read(), write()
#include <stdlib.h>  // For malloc(), free(), exit()
#include <stdio.h>   // for printf

#ifndef INT_MIN
#define INT_MIN (-2147483647 - 1)
#endif

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

typedef enum {
    false,
    true
} bool;

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;

typedef struct move {
    int ra;
    int rb;
	int rra;
	int rrb;
} move_t;

node_t	*remove_node(node_t **head);
void	insert_node_tail(node_t **head, node_t *new_node);
node_t	*create_node(int data);
node_t	*parse_list(int argc, char	**argv);
void	ft_list_print(const node_t *node, char c);
void	ft_lstclear(node_t **head);
void	ft_swap(node_t *head);
void	ft_push(node_t **list_from, node_t **list_to);
node_t	*ft_rotate(node_t **head);
node_t	*ft_reverse_rotate(node_t **head);
int		find_max(node_t *head);
int		find_antepenultimate_max(node_t *head, int max_index);
void	sort_three(node_t **head);
int		find_min(node_t *head);
int		find_antepenultimate_min(node_t *head, int min_index);
int		find_index(node_t *head, int value);
int		ft_list_size(node_t *node);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int a);
void	sort_list(node_t *head);
int		get_value_index(node_t *head, int index);
void	*ft_calloc(size_t count, size_t size);
bool	is_sorted(node_t *head);


#endif