/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:14:58 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 17:53:17 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stddef.h>
# include "node.h"

# define MAX_LOAD 0.6

typedef struct s_hashmap
{
	size_t	capacity;
	size_t	occupied;
	t_node	**array;
}	t_hashmap;

struct	s_main_state;

t_hashmap	*create_hashmap(size_t capacity);
int			double_capacity(t_hashmap **map);
int			add_item(t_hashmap **map, char *key, char *val);
int			add_entry(t_hashmap *map, char *key, char *val);
void		destroy_hashmap(t_hashmap *map);
size_t		hash_function(const char *str, size_t capacity);
int			init_state(struct s_main_state *st);
char		*chill_strdup(const char *s, int len);
int			clean_exit(t_hashmap *map, int exit_status);

#endif
