/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:17:06 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 17:01:45 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "alloc_utils.h"
#include <stdlib.h>

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
	map->array = ft_calloc(capacity, sizeof(t_node));
	map->capacity = capacity;
	map->occupied = 0;
	return (map);
}

void	double_capacity(t_hashmap **map)
{
	size_t		i;
	t_hashmap	*new_map;
	t_hashmap	*old_map;

	old_map = *map;
	new_map = create_hashmap(old_map->capacity << 1);
	i = 0;
	while (i < old_map->capacity)
	{
		if (old_map->array[i].key)
			add_entry(new_map, old_map->array[i].key, old_map->array[i].val);
		++i;
	}
	free(old_map->array);
	free(old_map);
	*map = new_map;
}

void	add_entry(t_hashmap *map, char *key, char *val)
{
	size_t		hash;

	hash = hash_function(key, map->capacity);
	if (map->array[hash].key == NULL)
	{
		map->array[hash].key = key;
		map->array[hash].val = val;
		++(map->occupied);
	}
}

void	add_item(t_hashmap **map, char *key, char *val)
{
	double		load;

	load = (double)(*map)->occupied / (double)(*map)->capacity;
	if (load > MAX_LOAD)
		double_capacity(map);
	add_entry(*map, key, val);
}

void	destroy_hashmap(t_hashmap *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		free(map->array[i].key);
		free(map->array[i].val);
		++i;
	}
	free(map->array);
	free(map);
}
