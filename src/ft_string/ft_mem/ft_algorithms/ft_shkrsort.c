/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shkrsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 06:46:22 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/26 06:46:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_algorithms.h"
#include <stddef.h>
#include <stdio.h>

#define INFS_LEFT	0
#define INFS_RIGHT	1
#define INFS_N_E	2
#define INFS_N_S	3

static void	*(*get_grabber(t_sort_order ord))(const void *data, t_arrinfo nf,
					t_data_cmp c)
{
	if (ord == FT_SORT_ORD_ASC)
		return (ft_getmin);
	return (ft_getmax);
}

static void	*(*get_grabber_r(t_sort_order ord))(const void *data, t_arrinfo nf,
					t_data_cmp c)
{
	if (ord == FT_SORT_ORD_ASC)
		return (ft_getmax);
	return (ft_getmin);
}

void	*ft_shkrsort(void *data, t_arrinfo nf, t_data_cmp cmp, int flag)
{
	const t_sort_order	ord = flag & FT_SORT_ORD_MASK;
	void				*elems;
	size_t				left;
	size_t				right;

	if (nf.nmemb < 2 || nf.sz < 1 || ord == FT_SORT_ORD_UNO || !data)
		return (data);
	left = 0;
	right = nf.nmemb - 1;
	while (left < right && !ft_is_sorted(data, nf.nmemb, nf.sz, cmp))
	{
		elems = get_grabber(ord)(data + left * nf.sz,
				(t_arrinfo){.sz = nf.sz,
				.nmemb = right - left + 1}, cmp);
		ft_swap(data + (left++) * nf.sz, elems, nf.sz);
		elems = get_grabber_r(ord)(data + left * nf.sz,
				(t_arrinfo){.sz = nf.sz,
				.nmemb = right - left + 1}, cmp);
		ft_swap(data + (right--) * nf.sz, elems, nf.sz);
	}
	return (data);
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
