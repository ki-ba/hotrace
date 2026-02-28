/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:03:44 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 15:07:27 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "hashmap.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	print_node(t_node node)
{
	ft_putstr(node.key);
	ft_putstr(":");
	ft_putstr(node.val);
}
void	print_hashmap(t_hashmap *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		if (map->array[i].key)
		{
			print_node(map->array[i]);
			ft_putstr("\n");
		}
		++i;
	}
}
