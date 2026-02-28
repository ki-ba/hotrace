/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:23:37 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/28 11:58:40 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_UTILS_H
# define ALLOC_UTILS_H

# include <stddef.h>

void		*ft_calloc(size_t nmemb, size_t size);
void		sfree(char **addr);

#endif
