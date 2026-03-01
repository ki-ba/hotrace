/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:33:07 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 18:34:16 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "hotrace.h"
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i])
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		++i;
	}
	if (i < n && s2[i])
		return (-1);
	return (0);
}

char	*chill_strdup(const char *s, int len)
{
	char	*dup;
	int		j;

	j = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (j < len)
	{
		dup[j] = s[j];
		j++;
	}
	dup[len] = '\0';
	return (dup);
}

int	clean_exit(t_hashmap *map, int exit_status)
{
	destroy_hashmap(map);
	return (exit_status);
}

int	init_state(struct s_main_state *st)
{
	st->word_len = 0;
	st->state = KEY;
	st->saved_key = NULL;
	st->map = create_hashmap(MAP_CAPACITY);
	if (!st->map)
		return (0);
	return (1);
}
