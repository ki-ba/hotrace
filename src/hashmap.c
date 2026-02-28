/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:17:06 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 16:25:07 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "alloc_utils.h"
#include "print_utils.h"
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

#include <stdio.h>
t_hashmap	*create_hashmap(size_t capacity)
{
	t_hashmap	*map;

	printf("creating new hashmap of capacity %zu\n", capacity);
	map = ft_calloc(1, sizeof(t_hashmap));
	map->array = ft_calloc(capacity, sizeof(t_node));
	map->capacity = capacity;
	map->occupied = 0;
	return (map);
}

t_hashmap	*double_capacity(t_hashmap *map)
{
	size_t		i;
	t_hashmap	*new_map;

	new_map = create_hashmap(map->capacity << 1);
	i = 0;
	while (i < map->capacity)
	{
		if (map->array[i].key)
		{
			add_item(new_map, map->array[i].key, map->array[i].val);
		}
		++i;
	}
	return (new_map);
}

t_hashmap	*add_item(t_hashmap *map, char *key, char *val)
{
	size_t		hash;
	double		load;
	t_hashmap	*new_map;

	load = (double)map->occupied / (double)map->capacity;
	if (load > MAX_LOAD)
		new_map = double_capacity(map);
	else
		new_map = map;
	hash = hash_function(key, map->capacity);
	if (new_map->array[hash].key != NULL)
	{
		printf("key %s has value %s : overwriting\n", new_map->array[hash].key, new_map->array[hash].val);
		free(new_map->array[hash].key);
		new_map->array[hash].key = NULL;
		free(new_map->array[hash].val);
		new_map->array[hash].val = NULL;
	}
	else
		++(new_map->occupied);
	new_map->array[hash].key = key;
	new_map->array[hash].val = val;
	print_hashmap(new_map);
	return (new_map);
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
