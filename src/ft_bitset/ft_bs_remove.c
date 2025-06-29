/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:40:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:19:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_bitset_types.h"
#include "ft_bitset.h"
#include "ft_string.h"
#include <stddef.h>

void	ft_bs_remove(t_bitset *bitset, size_t nbr)
{
	if (!bitset || !nbr)
		return ;
	if (bitset->_capacity <= nbr)
		return (ft_bs_free_inner(bitset));
	ft_bzero(bitset->bits + bitset->_capacity - nbr, nbr);
	bitset->_capacity -= nbr;
	return ;
}

void	ft_bs_remove_front(t_bitset *bitset, uint8_t nbr)
{
	if (!bitset || !nbr)
		return ;
	if (bitset->_capacity <= nbr)
		return (ft_bs_free_inner(bitset));
	ft_bzero(bitset->bits, nbr);
	ft_memmove(bitset->bits, bitset->bits + nbr,
		bitset->_capacity - nbr);
	bitset->_capacity -= nbr;
	return ;
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
