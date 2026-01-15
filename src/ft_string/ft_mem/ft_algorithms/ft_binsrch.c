/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:36:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 14:16:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_binsrch(const void *data, const t_arrinfo infos, const void *elem,
					t_data_cmp cmp)
{
	const size_t	nb_elem = infos.nmemb;
	const size_t	e_size = infos.sz;
	const char		*byte_data = data;
	const char		*mid_elem;
	int				ret;

	if (nb_elem == 0 || e_size == 0 || !data)
		return (0);
	mid_elem = byte_data + ((nb_elem - 1) / 2) * e_size;
	ret = cmp(mid_elem, elem);
	if (ret == 0)
		return ((size_t)((mid_elem - byte_data) / e_size));
	else if (ret > 0)
		return (ft_binsrch(byte_data, (t_arrinfo){
				.nmemb = (nb_elem - 1) / 2,
				.sz = e_size}, elem, cmp));
	return (ft_binsrch(mid_elem + e_size, (t_arrinfo){
			.nmemb = nb_elem / 2,
			.sz = e_size}, elem, cmp)
		+ (nb_elem - 1) / 2 + 1);
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
