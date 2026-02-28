/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:27:01 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 18:54:11 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "hotrace.h"
#include <stddef.h>
#include <unistd.h>
#include "alloc_utils.h"
#include <stdlib.h>
#include "str_utils.h"
#include "print_utils.h"

t_node	*new_node(char *key, char *val)
{
	t_node	*node;

	if (!key || !val)
		return (NULL);
	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->key = key;
	node->val = val;
	return (node);
}

t_node	*last(t_node *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

int	check_duplicate(t_node **head, t_node *new)
{
	t_node	*current;

	current = *head;
	while (current)
	{
		if (ft_strncmp(current->key, new->key, ft_strlen(current->key)) == 0)
		{
			free(new->key);
			free(new->val);
			free(new);
			return (TRUE);
		}
		current = current->next;
	}
	return (FALSE);
}

int	add_back(t_node **head, t_node *new)
{
	t_node	*last_node;
	int		dup;

	if (!new || !head)
		return (0);
	dup = check_duplicate(head, new);
	if (dup)
		return (dup == 0);
	last_node = last(*head);
	if (!last_node)
		*head = new;
	else
		last_node->next = new;
	return (1);
}

void	clear_lst(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->val);
		current->next = NULL;
		free(current);
		current = next;
	}
	*head = NULL;
}
