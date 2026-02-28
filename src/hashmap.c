/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:17:06 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 19:15:25 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "node.h"
#include "alloc_utils.h"
#include <stdlib.h>
#include "hotrace.h"

size_t	hash_function(const char *str, size_t capacity)
{
	size_t	hash;
	size_t	i;

	hash = 5381;
	i = 0;
	while (str[i])
	{
		hash = ((hash << 5) + hash) + (unsigned char)str[i];
		i++;
	}
	return (hash % capacity);
}

t_hashmap	*create_hashmap(size_t capacity)
{
	t_hashmap	*map;

	map = ft_calloc(1, sizeof(t_hashmap));
	if (!map)
		return (NULL);
	map->array = ft_calloc(capacity, sizeof(t_node));
	if (!map->array)
	{
		free(map);
		return (NULL);
	}
	map->capacity = capacity;
	map->occupied = 0;
	return (map);
}

int	add_entry(t_hashmap *map, char *key, char *val)
{
	size_t		hash;
	t_node		*node;

	hash = hash_function(key, map->capacity);
	node = new_node(key, val);
	if (!node)
		return (ERR_ALLOC);
	(map->occupied) += add_back(&(map->array[hash]), node);
	return (SUCCESS);
}

int	add_item(t_hashmap **map, char *key, char *val)
{
	double		load;

	load = (double)(*map)->occupied / (double)(*map)->capacity;
	if (load > MAX_LOAD)
		if (double_capacity(map))
			return (ERR_ALLOC);
	if (add_entry(*map, key, val))
		return (ERR_ALLOC);
	return (SUCCESS);
}

void	destroy_hashmap(t_hashmap *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		clear_lst(&map->array[i]);
		++i;
	}
	free(map->array);
	free(map);
}
