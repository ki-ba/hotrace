/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfilegen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:10:14 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 17:17:47 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>

# define N_VALUES 1e6
int main(void)
{
	size_t i = 0;
	int fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);

	while (i < N_VALUES)
	{
		dprintf(fd, "key%zu\n", i);
		dprintf(fd, "value%zu\n", i);
		i++;
	}
	dprintf(fd, "\n");
	i = 0;
	while (i < N_VALUES)
	{
		if (i == 50000)
			dprintf(fd, "ZINZIN\n");
		dprintf(fd, "key%zu\n", i);
		i++;
	}
	return (0);
}
