/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:51:21 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <stddef.h>

size_t	ft_align_multiple_2(size_t size, size_t pow_2)
{
	return ((size + pow_2 - 1) & ~(pow_2 - 1));
}

size_t	ft_align_2(size_t size)
{
	return ((size + 2 - 1) & ~(2 - 1));
}

size_t	ft_align(size_t size, size_t alignment)
{
	if (alignment < 2)
		return (size);
	if (size % alignment == 0)
		return (size);
	return (size + (alignment - size % alignment));
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
