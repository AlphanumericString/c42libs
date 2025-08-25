/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:04:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 03:55:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_bitset_types.h"
#include "ft_bitset.h"
#include "ft_string.h"

void	ft_bs_clear(t_bitset *bitset)
{
	if (!bitset)
		return ;
	ft_bzero(bitset->bits, sizeof(t_bitset8) * bitset->_capacity);
	return ;
}

void	ft_bs_free(t_bitset **bitset)
{
	if (!bitset || !*bitset)
		return ;
	if ((*bitset)->bits)
		ft_free((*bitset)->bits);
	ft_free_clear((void **)bitset);
	return ;
}

void	ft_bs_free_inner(t_bitset *bitset)
{
	if (!bitset)
		return ;
	ft_free_clear((void **)&bitset->bits);
	bitset->_capacity = 0;
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
