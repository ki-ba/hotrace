/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfilegen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:10:14 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 14:14:41 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	size_t i = 0;
	int fd = open("test.txt", O_RDWR | O_APPEND | O_CREAT, 0644);

	while (i < 1000)
	{
		dprintf(fd, "key%zu\n", i);
		dprintf(fd, "value%zu\n", i);
		i++;
	}
	dprintf(fd, "\n");
	i = 0;
	while (i < 1000)
	{
		dprintf(fd, "key%zu\n", i);
		i++;
	}
	return (0);
}
