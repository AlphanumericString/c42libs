/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:24:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/13 18:16:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_bzero(void)
{
	int			off;
	char		str[10];
	size_t		tab[10];

	ft_bzero(str, 10);
	ft_bzero(&off, sizeof(int));
	while (off < 10)
		if (str[off++] != 0)
			return (off);
	ft_bzero(tab, 10 * sizeof(size_t));
	off = 0;
	while (off < 10)
		if (tab[off++] != 0)
			return (off + 10);
	ft_bzero(tab, 0);
	ft_bzero(NULL, 999);
	return (0);
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
