/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:46:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 01:04:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

#define MAGIC_LO 0x0101010101010101
#define MAGIC_HI 0x8080808080808080

#define L_WORD 0
#define HI_MGC 1
#define LO_MGC 2

static int	_slen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlen(const char *str)
{
	const char	*src = str;
	size_t		*ptr_s;
	size_t		i;
	size_t		magic[3];

	while (*str && (size_t)str % sizeof(size_t))
		str++;
	if (!*str)
		return (str - src);
	i = 0;
	ptr_s = (size_t *)str;
	magic[HI_MGC] = MAGIC_HI;
	magic[LO_MGC] = MAGIC_LO;
	magic[L_WORD] = ptr_s[0];
	while (1)
	{
		magic[L_WORD] = ptr_s[i];
		if ((magic[L_WORD] - magic[LO_MGC]) & ~magic[L_WORD] & magic[HI_MGC])
			break ;
		i++;
	}
	return (_slen((char *)(&ptr_s[i])) + (str - src) + i * sizeof(size_t));
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
