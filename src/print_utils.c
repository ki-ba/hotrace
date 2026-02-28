/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:03:44 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 13:37:22 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

static size_t ft_strlen(const char *s) {
  int i;

  if (!s)
    return (0);
  i = 0;
  while (s[i])
    ++i;
  return (i);
}

void ft_putstr(char *s) {
  if (!s)
    return;
  write(1, s, ft_strlen(s));
}
