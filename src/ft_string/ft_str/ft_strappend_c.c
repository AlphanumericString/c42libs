/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:02:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/22 17:38:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"

char	*ft_strappend_c(char **str, char c)
{
	size_t	len;
	char	*prev;

	if (!str)
		return (NULL);
	len = 0;
	if (*str)
		len = ft_strlen(*str);
	prev = *str;
	*str = ft_calloc(len + 2, sizeof(char));
	if (!*str)
		return (*str = prev, NULL);
	ft_memcpy(*str, prev, len);
	(*str)[len] = c;
	(*str)[len + 1] = '\0';
	ft_free(prev);
	return (*str);
}
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
