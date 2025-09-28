/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bblsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:54:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/07 20:54:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_algorithms.h"
#include "internal/algo_util.h"

size_t	*ft_sbblsort(size_t *data, size_t nb_elem, int flags)
{
	return (ft_bblsort(data, (t_arrinfo){
			.nmemb = nb_elem,
			.sz = sizeof(size_t)}, (t_data_cmp)ft_cmp_szt_p, flags), data);
}

ssize_t	*ft_ssbblsort(ssize_t *data, size_t nb_elem, int flags)
{
	return (ft_bblsort(data, (t_arrinfo){
			.nmemb = nb_elem,
			.sz = sizeof(ssize_t)}, (t_data_cmp)ft_cmp_sszt_p, flags), data);
}

void	*ft_bblsort(void *data, const t_arrinfo infos, t_data_cmp cmp, int flg)
{
	const size_t		se = infos.sz;
	const size_t		nb = infos.nmemb;
	const t_sort_order	order = (flg & FT_SORT_ORD_MASK);
	size_t				i;

	if (nb < 2 || se == 0 || order == FT_SORT_ORD_UNO)
		return ((void *)data);
	i = 1;
	while (i < nb)
	{
		if (!ft_isord_ok(order, cmp(data + (i - 1) * se, data + i * se)))
		{
			ft_swap(data + (i - 1) * se, data + i * se, se);
			i = 0;
		}
		i++;
	}
	return ((t_any) data);
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
