/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mrgsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:16:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 14:16:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_algorithms.h"
#include "internal/mrgsort.h"

// pseudo code:
// take : data, left index, right index)
// -> if right - left <= 1
//	-> return ;
// -> recurse for left part
// -> recurse for right part
// -> merge: while left_offset < mid && right_offset < right
// => add either ((left < right)? left : right) to tmp
// copy remainer of (left || right)
// copy tmp to data

static void	copy_remainer(t_minfo infos, void *data, size_t ofst[3],
				size_t mid)
{
	ft_memcpy(infos.anf.buf + ofst[TMP] * infos.anf.s_e, data
		+ (ofst[LEFT] + infos.lft) * infos.anf.s_e,
		infos.anf.s_e * (mid - (ofst[LEFT] + infos.lft)));
	ft_memcpy(infos.anf.buf + ofst[TMP] * infos.anf.s_e,
		data + (ofst[RIGHT] + mid) * infos.anf.s_e,
		infos.anf.s_e * (infos.rgt - (ofst[RIGHT] + mid) + 1));
	ft_memcpy(data + infos.lft * infos.anf.s_e, infos.anf.buf,
		infos.anf.s_e * (infos.rgt - infos.lft + 1));
}

static void	*mrgsort_internal(void *data, t_minfo nf)
{
	size_t	mid;
	size_t	offsets[3];

	if (nf.rgt - nf.lft < 1)
		return (data);
	mid = (nf.lft + nf.rgt) / 2 + 1;
	mrgsort_internal(data, (t_minfo){nf.anf, nf.lft, 0, mid - 1});
	mrgsort_internal(data, (t_minfo){nf.anf, mid, 0, nf.rgt});
	ft_bzero(offsets, sizeof(offsets));
	while (offsets[LEFT] + nf.lft < mid && offsets[RIGHT] + mid <= nf.rgt)
	{
		if (nf.anf.cmp(data + (offsets[LEFT] + nf.lft) * nf.anf.s_e,
				data + (offsets[RIGHT] + mid) * nf.anf.s_e) <= 0)
			ft_memcpy(nf.anf.buf + offsets[TMP]++ *nf.anf.s_e,
				data + (offsets[LEFT]++ + nf.lft) * nf.anf.s_e,
				nf.anf.s_e);
		else
			ft_memcpy(nf.anf.buf + offsets[TMP]++ *nf.anf.s_e,
				data + (offsets[RIGHT]++ + mid) * nf.anf.s_e,
				nf.anf.s_e);
	}
	return (copy_remainer(nf, data, offsets, mid), data);
}

void	*ft_mrgsort_r(void *data, t_arrinfo infos, t_data_cmp cmp, void *buff)
{
	t_minfo	merge;

	if (infos.nmemb < 2 || infos.sz < 1)
		return (data);
	merge.anf.buf = buff;
	merge.anf.cmp = cmp;
	merge.anf.n_e = infos.nmemb;
	merge.anf.s_e = infos.sz;
	merge.lft = 0;
	merge.mid = 0;
	merge.rgt = infos.nmemb - 1;
	return (mrgsort_internal(data, merge));
}

void	*ft_mrgsort(void *data, t_arrinfo infos, t_data_cmp cmp, int flag)
{
	const t_sort_order	ord = flag & FT_SORT_ORD_MASK;
	char				loc_buff[FT_STD_BUF_SIZE];
	void				*buffer;
	void				*ret;

	buffer = NULL;
	if (ord == FT_SORT_ORD_UNO)
		return (data);
	if (ord == FT_SORT_ORD_DES)
		return (ft_memnrev(ft_mrgsort(data, infos, cmp, FT_SORT_ORD_ASC),
				infos.nmemb, infos.sz));
	if (infos.nmemb * infos.sz <= FT_STD_BUF_SIZE)
		buffer = loc_buff;
	if (!buffer)
		buffer = ft_malloc(infos.nmemb * infos.sz);
	if (!buffer)
		return (NULL);
	ret = ft_mrgsort_r(data, infos, cmp, buffer);
	if (buffer != loc_buff)
		ft_free(buffer);
	return (ret);
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
