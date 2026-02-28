/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:44:38 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 18:29:13 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

typedef struct s_node
{
	char			*key;
	char			*val;
	struct s_node	*next;
}	t_node;

t_node	*new_node(char *key, char *val);
t_node	*last(t_node *node);
int		add_back(t_node **head, t_node *new);
void	clear_lst(t_node **head);

#endif
