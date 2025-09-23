/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:01:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/07 23:01:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

// NOTE: maybe rename to ft_algos.h

// defs -> size_t, ssize_t, NULL, bool ...
# include "ft_defs.h"
# include "sys/cdefs.h"

typedef struct arr_info
{
	size_t		n_ele;
	size_t		ele_s;
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

#endif // !FT_SORT_H
