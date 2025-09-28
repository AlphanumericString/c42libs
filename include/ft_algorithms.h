/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:01:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/27 15:15:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHMS_H
# define FT_ALGORITHMS_H

// NOTE: maybe rename to ft_algos.h

// defs -> size_t, ssize_t, NULL, bool ...
# include "ft_defs.h"

// TODO: move to ft_arr
typedef struct arr_info
{
	size_t		nmemb;
	size_t		sz;
}	t_arrinfo;

// cmp utils
// rcmp
int			ft_cmp_rptr(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));
int			ft_cmp_rint_p(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));
int			ft_cmp_rszt_p(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));
int			ft_cmp_rsszt_p(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));
// cmp
int			ft_cmp_ptr(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));
int			ft_cmp_szt_p(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));
int			ft_cmp_sszt_p(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));
int			ft_cmp_int_p(const void *a, const void *b)
			__attribute__((nonnull(1, 2), hot));

// srch
size_t		ft_binsrch(const void *data, const t_arrinfo infos,
				const void *elem, t_data_cmp cmp)
			__attribute__((nonnull(1, 4)));

// buble sort - dont use.
ssize_t		*ft_ssbblsort(ssize_t *data, size_t nb_elem, int flags)
			__attribute__((nonnull(1)));
size_t		*ft_sbblsort(size_t *data, size_t nb_elem, int flags)
			__attribute__((nonnull(1)));
void		*ft_bblsort(void *data, const t_arrinfo i, t_data_cmp cmp,
				int flags) __attribute__((nonnull(1, 3)));

// bucket sort - dont use for large collections. great at medium targets.
size_t		*ft_sbcksort(size_t *data, size_t nb_elem,
				int flags) __attribute__((nonnull(1)));

// insertion sort - good for small collections.
size_t		*ft_sisrtsort(size_t *data, size_t nb_e, int flags)
			__attribute__((nonnull(1)));
ssize_t		*ft_ssisrtsort(ssize_t *data, size_t nb_e, int flags)
			__attribute__((nonnull(1)));
void		*ft_isrtsort( void *data, const t_arrinfo infos, t_data_cmp cmp,
				int flags) __attribute__((nonnull(1, 3)));
void		*ft_isrtsort_b(void *data, const t_arrinfo infos, t_data_cmp cmp,
				void *buff) __attribute__((nonnull(1, 3, 4)));

// selection sort (aka bblsort wihout the reset to 0 after every swap)
void		*ft_slctsort(void *data, const t_arrinfo infos, t_data_cmp cmp,
				int fg) __attribute__((nonnull(1, 3)));

// shakersort
void		*ft_shkrsort(void *data, t_arrinfo nf, t_data_cmp cmp, int flag)
			__attribute__((nonnull(1, 3)));

// mergesort
void		*ft_mrgsort_r(void *data, t_arrinfo infos, t_data_cmp cmp,
				void *buff) __attribute__((nonnull(1, 3, 4)));
void		*ft_mrgsort(void *data, t_arrinfo info, t_data_cmp cmp, int flag)
			__attribute__((nonnull(1, 3)));

/// @brief sort the memory with the cmp function by chunks of size
/// @param array pointer to the memory
/// @param nmb number of chunks
/// @param size size of each chunk
/// @param cmp comparison function
/// @warning Do not use. Not implemented fully.
void		ft_qsort(void *array, size_t nmb, size_t size, t_data_cmp cmp)
			__attribute__((nonnull(1, 4)));

bool		ft_is_sorted(void *array, size_t nmb, size_t size,
				t_data_cmp cmp) __attribute__((nonnull(1, 4)));
void		*ft_getmax(const void *data, t_arrinfo infos,
				t_data_cmp cmp) __attribute__((nonnull(1, 3)));
void		*ft_getmin(const void *data, t_arrinfo infos,
				t_data_cmp cmp) __attribute__((nonnull(1, 3)));

#endif // !FT_ALGORITHMS_H
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
