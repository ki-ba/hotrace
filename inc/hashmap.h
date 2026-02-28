/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:14:58 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 13:15:25 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stddef.h>

typedef struct s_hashmap
{
	size_t	capacity;
	size_t	occupied;
	char	**array;
}	t_hashmap;

t_hashmap	*create_hashmap(size_t capacity);
t_hashmap	*double_capacity(t_hashmap *map);
void		add_item(t_hashmap *map, char *key, char *val);
void		destroy_hashmap(t_hashmap *map);
size_t		hash_function(const char *str, size_t capacity);

#endif
