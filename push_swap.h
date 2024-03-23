/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:54 by cyril             #+#    #+#             */
/*   Updated: 2024/03/23 13:28:21 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>  // For read(), write()
#include <stdlib.h>  // For malloc(), free(), exit()
#include <stdio.h>   // for printf

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;

node_t	*remove_node(node_t **head);
void	insert_node_tail(node_t **head, node_t *new_node);
node_t	*create_node(int data);
node_t	*parse_list(int argc, char	**argv);
void	ft_list_print(node_t *node);
void	ft_lstclear(node_t **head);

#endif