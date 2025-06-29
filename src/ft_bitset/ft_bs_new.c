/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:01:37 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 21:13:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "types/ft_bitset_types.h"
#include "ft_allocator__dev.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

t_bitset	*ft_bs_new(size_t size)
{
	t_bitset	*bitset;

	bitset = ft_calloc(sizeof(t_bitset), 1);
	if (!bitset)
		return (NULL);
	if (!size)
		return (bitset);
	bitset->_capacity = (size + 7) / 8;
	bitset->bits = ft_calloc(sizeof(t_bitset8), bitset->_capacity);
	if (!bitset->bits)
		return (ft_free(bitset), NULL);
	return (bitset);
}

t_bitset	ft_bs_create(size_t size)
{
	t_bitset	bitset;

	if (!size)
	{
		bitset._capacity = 0;
		bitset.bits = NULL;
		return (bitset);
	}
	bitset._capacity = (size + 7) / 8;
	bitset.bits = ft_calloc(sizeof(t_bitset8), bitset._capacity);
	if (!bitset.bits)
	{
		bitset._capacity = 0;
		return (bitset);
	}
	ft_bzero(bitset.bits, sizeof(t_bitset8) * bitset._capacity);
	return (bitset);
}

t_bitset	*ft_bs_new_from_mem(const void *str_p, size_t n)
{
	t_bitset	*bitset;
	size_t		i;
	const char	*str = str_p;

	if (!str || !n)
		return (NULL);
	bitset = ft_bs_new(n * 8);
	i = 0;
	while (i < n)
	{
		ft_bs_set_raw(bitset, i, str[i]);
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
