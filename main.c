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
#include "print_utils.h"
#include <stdlib.h>

static void	handle_search(t_main_state *st, char *word)
{
	int	hash;

	hash = hash_function(word, st->map->capacity);
	if (st->map->array[hash] && st->map->array[hash]->key)
		ft_putstr(st->map->array[hash]->val);
	else
	{
		ft_putstr(word);
		ft_putstr(": Not found.");
	}
	ft_putstr("\n");
}

static int	process_val(t_main_state *st, char *word)
{
	char	*saved_val;

	saved_val = chill_strdup(word, st->word_len);
	if (!saved_val)
		return (ERR_ALLOC);
	if (add_item(&(st->map), st->saved_key, saved_val))
	{
		free(saved_val);
		return (GENERIC_ERROR);
	}
	st->saved_key = NULL;
	st->state = KEY;
	return (0);
}

static int	process_word(t_main_state *st, char *word)
{
	if (st->word_len == 0 && st->state != SEARCH)
		st->state = SEARCH;
	else if (st->state == VAL)
		return (process_val(st, word));
	else if (st->state == KEY)
	{
		st->saved_key = chill_strdup(word, st->word_len);
		if (!st->saved_key)
			return (ERR_ALLOC);
		st->state = VAL;
	}
	else if (st->state == SEARCH && st->word_len > 0)
		handle_search(st, word);
	return (0);
}

static int	parse_buffer(t_main_state *st, char *buf,\
	ssize_t b_read, char *word)
{
	ssize_t	i;
	int		ret;

	i = 0;
	while (i < b_read)
	{
		if (buf[i] == '\n')
		{
			word[st->word_len] = '\0';
			ret = process_word(st, word);
			if (ret != 0)
				return (ret);
			st->word_len = 0;
		}
		else
		{
			word[st->word_len] = buf[i];
			st->word_len++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char			buf[BUF_SIZE];
	char			word[BUF_SIZE];
	ssize_t			b_read;
	int				ret;
	t_main_state	st;

	(void)argv;
	if (argc > 1)
		return (write(1, "no args pls\n", 12) * 0 + 1);
	if (!init_state(&st))
		return (ERR_ALLOC);
	b_read = read(STDIN_FILENO, buf, BUF_SIZE);
	while (b_read > 0)
	{
		ret = parse_buffer(&st, buf, b_read, word);
		if (ret != 0)
		{
			free(st.saved_key);
			return (clean_exit(st.map, ret));
		}
		b_read = read(STDIN_FILENO, buf, BUF_SIZE);
	}
	destroy_hashmap(st.map);
	free(st.saved_key);
	return (0);
}
