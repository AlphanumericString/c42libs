/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:05:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

static void	byte_bzero(char *s, size_t n)
{
	while (n--)
	{
		*s = 0;
		s++;
	}
}

static void	word_bzero(size_t *s, size_t *n)
{
	size_t	word_count;
	size_t	i;

	word_count = *n / sizeof(size_t);
	i = 0;
	while (i < word_count)
	{
		s[i] = 0;
		i++;
	}
	*n %= sizeof(size_t);
}

void	ft_bzero(void *s, size_t n)
{
	if (!n || !s)
		return ;
	if (n < sizeof(size_t))
		return (byte_bzero(s, n));
	byte_bzero(s, (size_t)s % sizeof(size_t));
	n -= (size_t)s % sizeof(size_t);
	s += (size_t)s % sizeof(size_t);
	word_bzero(s, &n);
	byte_bzero(s, n);
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
