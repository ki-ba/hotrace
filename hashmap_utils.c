/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:15:18 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 19:15:34 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include <stdlib.h>

int	double_capacity(t_hashmap **map)
{
	size_t		i;
	t_hashmap	*new_map;
	t_hashmap	*old_map;
	t_node		*current_node;
	t_node		*next_node;

	old_map = *map;
	new_map = create_hashmap(old_map->capacity << 1);
	i = -1;
	while (new_map && ++i < old_map->capacity)
	{
		current_node = (old_map->array[i]);
		while (current_node)
		{
			add_entry(new_map, current_node->key, current_node->val);
			next_node = current_node->next;
			free(current_node);
			current_node = next_node;
		}
	}
	free(old_map->array);
	free(old_map);
	*map = new_map;
	return (*map == NULL);
}
