/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:20:34 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 19:20:32 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "hashmap.h"
#include <unistd.h>
#include <print_utils.h>
#include <stdlib.h>

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

// TODO: MAYBE a big area if malloc is too slow
// FIXME: double free l. 122

int	main(int argc, char *argv[])
{
	char	buf[BUF_SIZE];
	ssize_t	bytes_read;
	int		state;
	int		hash;
	int		word_len;
	char	current_word[BUF_SIZE];
	char	*saved_key = NULL;

	(void)argv;
	if (argc > 1)
		return (write(1, "no args pls\n", 13) - 12);
	word_len = 0;
	state = KEY;
	t_hashmap	*map = create_hashmap(MAP_CAPACITY);
	if (!map)
		return (ERR_ALLOC);
	while ((bytes_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		ssize_t	i = 0;
		while (i < bytes_read)
		{
			if (buf[i] == '\n')
			{
				current_word[word_len] = '\0';
				if (word_len == 0 && state != SEARCH)
					state = SEARCH;
				else if (state == VAL)
				{
					char	*saved_value = chill_strdup(current_word, word_len);
					if (!saved_value)
					{
						free(saved_key);
						return (clean_exit(map, ERR_ALLOC));
					}
					if (add_item(&map, saved_key, saved_value))
					{
						free(saved_key);
						saved_key = NULL;
						free(saved_value);
						saved_value = NULL;
						return(clean_exit(map, GENERIC_ERROR));
					}
					state = KEY;
				}
				else if (state == KEY)
				{
					saved_key = chill_strdup(current_word, word_len);
					if (!saved_key)
						return (clean_exit(map, ERR_ALLOC));
					state = VAL;
				}
				else if (state == SEARCH && word_len > 0)
				{
					hash = hash_function(current_word, map->capacity);
					if (map->array[hash])
						ft_putstr(map->array[hash]->val);
					else
					{
						ft_putstr(current_word);
						ft_putstr(": Not found.");
					}
					ft_putstr("\n");
				}
				word_len = 0;
			}
			else
			{
				current_word[word_len] = buf[i];
				word_len++;
			}
			i++;
		}
	}
	destroy_hashmap(map);
	if (saved_key)
		free(saved_key);
	return (0);
}
