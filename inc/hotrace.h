/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:57:22 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 19:19:08 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include "hashmap.h"

typedef enum e_status
{
	SUCCESS = 0,
	GENERIC_ERROR = 1,
	ERR_ALLOC = 3
}	t_status;

typedef enum e_state
{
	KEY = 0,
	VAL = 1,
	SEARCH = 2
}	t_state;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

# define BUF_SIZE 4096
# define MAP_CAPACITY 2e5

typedef struct s_main_state
{
	int			state;
	int			word_len;
	char		*saved_key;
	t_hashmap	*map;
}	t_main_state;

#endif
