/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slctsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:17:03 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 14:17:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_algorithms.h"
#include <stdio.h>

void	*ft_slctsort(void *data, const t_arrinfo infos,
			t_data_cmp cmp, int fg)
{
	const t_sort_order	ord = fg & FT_SORT_ORD_MASK;
	void				*elem;
	size_t				i;

	if (ord == FT_SORT_ORD_UNO || infos.sz == 0 || infos.nmemb < 2)
		return (data);
	i = 0;
	while (i != infos.nmemb - 1)
	{
		if (ord == FT_SORT_ORD_DES)
			elem = ft_getmax(data + i * infos.sz,
					(t_arrinfo){infos.nmemb - i, infos.sz}, cmp);
		if (ord == FT_SORT_ORD_ASC)
			elem = ft_getmin(data + i * infos.sz,
					(t_arrinfo){infos.nmemb - i, infos.sz}, cmp);
		ft_swap(data + (i++) * infos.sz, elem, infos.sz);
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
