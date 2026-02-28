/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:17:06 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 13:30:33 by kbarru           ###   ########lyon.fr   */
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

t_hashmap	*create_hashmap(size_t capacity)
{
	t_hashmap	*map;

	map = ft_calloc(1, sizeof(t_hashmap));
	map->array = ft_calloc(capacity, sizeof(char *));
	map->capacity = capacity;
	return (map);
}

t_hashmap	*double_capacity(t_hashmap *map)
{
	char	**array;
	size_t	index;

	index = -1;
	array = ft_calloc(map->capacity << 1, sizeof(char *));
	while (++index < map->capacity)
		array[index] = map->array[index];
	map->capacity <<= 1;
	free(map->array);
	map->array = array;
	return (NULL);
}

void	add_item(t_hashmap *map, char *key, char *val)
{
	size_t	hash;
	size_t	double_count;

	double_count = 0;
	hash = hash_function(key, map->capacity);
	while (map->array[hash] != NULL && double_count++ < 4)
	{
		ft_putstr("collision detected; doubling array size\n");
		double_capacity(map);
		hash = hash_function(key, map->capacity);
	}
	if (map->array[hash] != NULL)
	{
		free(map->array[hash]);
		map->array[hash] = NULL;
	}
	else
		++(map->occupied);
	map->array[hash] = val;
}

void	destroy_hashmap(t_hashmap *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		free(map->array[i]);
		++i;
	}
	free(map->array);
	free(map);
}

void	print_hashmap(t_hashmap *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		if (map->array[i])
			ft_putstr(map->array[i]);
		else
			ft_putstr("[void]");
		ft_putstr("\n");
		++i;
	}
}
