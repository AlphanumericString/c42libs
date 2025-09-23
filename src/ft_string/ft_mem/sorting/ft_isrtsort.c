/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrtsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:25:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/14 18:25:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t	*ft_sisrtsort(size_t *data, size_t nb_e, int flags)
{
	return (ft_isrtsort(data, (t_arrinfo){
			.n_ele = nb_e,
			.ele_s = sizeof(size_t)}, (t_data_cmp)ft_cmp_szt_p, flags), data);
}

ssize_t	*ft_ssisrtsort(ssize_t *data, size_t nb_e, int flags)
{
	return (ft_isrtsort(data, (t_arrinfo){
			.n_ele = nb_e,
			.ele_s = sizeof(ssize_t)}, (t_data_cmp)ft_cmp_sszt_p, flags), data);
}

void	*ft_isrtsort_b(void *data, const t_arrinfo infos, t_data_cmp cmp,
			void *buff)
{
	size_t				i_place;
	size_t				i;

	if (infos.n_ele < 2 || infos.ele_s < 1)
		return (data);
	i = 1;
	i_place = 0;
	while (i != infos.n_ele)
	{
		if (cmp(data + (i - 1) * infos.ele_s, data + i * infos.ele_s) > 0)
		{
			ft_memcpy(buff, (data + i * infos.ele_s), infos.ele_s);
			i_place = ft_binsrch(data, (t_arrinfo){i, infos.ele_s}, buff, cmp);
			ft_memmove((data + (i_place + 1) * infos.ele_s),
				(data + i_place * infos.ele_s),
				(i - i_place) * infos.ele_s);
			ft_memcpy((t_any)(data + i_place * infos.ele_s), buff, infos.ele_s);
		}
		i++;
	}
	return (data);
}

void	*ft_isrtsort(void *data, const t_arrinfo infos, t_data_cmp cmp, int flg)
{
	const t_sort_order	ord = flg & FT_SORT_ORD_MASK;
	void				*tmp;

	if (infos.n_ele < 2 || infos.ele_s < 1 || ord == FT_SORT_ORD_UNO)
		return (data);
	if (ord == FT_SORT_ORD_DES)
		return (ft_memnrev(ft_isrtsort(data, infos, cmp, FT_SORT_ORD_ASC),
				infos.n_ele, infos.ele_s));
	tmp = ft_calloc(1, infos.ele_s);
	if (tmp)
		ft_isrtsort_b(data, infos, cmp, tmp);
	return (ft_free(tmp), data);
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
