/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:20:34 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 17:11:38 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "hashmap.h"
#include <unistd.h>
#include <print_utils.h>
#include <stdlib.h>

char *chill_strdup(const char *s, int len)
{
	char *dup;
	int j;

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

// state : 0 = key | 1 = value | 2 = search mode
// TODO: MAYBE a big area if malloc is too slow

int main(void)
{
	char buf[BUF_SIZE];
	ssize_t bytes_read;
	int state;
	int hash;
	int word_len;
	char current_word[BUF_SIZE];
	char *saved_key = NULL;

	word_len = 0;
	state = 0;

	t_hashmap *map = create_hashmap(MAP_CAPACITY);

	while ((bytes_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		ssize_t i = 0;
		while (i < bytes_read)
		{
			if (buf[i] == '\n')
			{
				current_word[word_len] = '\0';

				if (word_len == 0 && state != 2)
				{
					state = 2;
				}
				else if (state == 1)
				{
					char *saved_value = chill_strdup(current_word, word_len);
					add_item(&map, saved_key, saved_value);
					state = 0;
				}
				else if (state == 0)
				{
					saved_key = chill_strdup(current_word, word_len);
					state = 1;
				}
				else if (state == 2 && word_len > 0)
				{
					hash = hash_function(current_word, map->capacity);
					if (map->array[hash].key)
					{
						ft_putstr(map->array[hash].val);
					}
					else
					{
						ft_putstr(current_word);
						ft_putstr(" : Not found.");
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
	// print_hashmap(map);
	destroy_hashmap(map);
	// if (saved_key)
	// 	free(saved_key);
	return 0;
}

