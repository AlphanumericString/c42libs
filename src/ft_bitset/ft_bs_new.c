/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:01:37 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/10 13:50:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "ft_bitset_types.h"
#include "ft_allocator__dev.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

t_bitset *ft_bs_new(size_t size)
{
	t_bitset	*bitset;

	bitset = ft_calloc(sizeof(t_bitset), 1);
	if (!bitset)
		return (NULL);
	bitset->_capacity = (size + 7) / 8;
	bitset->bits = ft_calloc(sizeof(t_bitset8), bitset->_capacity);
	if (!bitset->bits)
		return (ft_free(bitset), NULL);
	return (bitset);
}

t_bitset ft_bs_create(size_t size)
{
	t_bitset	bitset;

	bitset._capacity = (size + 7) / 8;
	bitset.bits = ft_calloc(sizeof(t_bitset8), bitset._capacity);
	if (!bitset.bits)
		ft_bzero(&bitset, sizeof(t_bitset));
	return (bitset);
}

t_bitset *ft_bs_new_from_str(const char *str, size_t n)
{
	t_bitset	*bitset;
	size_t		i;

	if (!str || !n)
		return (NULL);
	bitset = ft_bs_new(n * 8);
	i = 0;
	while (i < n)
	{
		ft_bs_set_raw(bitset, i, (uint8_t)str[i]);
		i++;
	}
	return (bitset);
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
