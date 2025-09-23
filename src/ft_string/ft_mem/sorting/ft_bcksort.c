/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bcksort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:59:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/07 20:59:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bucket sort.
//		https://en.wikipedia.org/wiki/Bucket_sort
// algo:
//	1. create k empty buckets (size of k given by user)
//	2. find maximum value in data
//	3. for elem in array:
//		put elem in bucket[elem * k / max_val]
//	4. sort each bucket with another sorting algo (quick, merge, bubble, ...)
//	5. concatenate all buckets into data by order
//	6. return data
//
// notes:
//	problem -> void *... how am i meant to use that to find max value?
//	-> user must provide a function to map data to a [s]size_t value?
//	-> only accept [s]size_t data?
//
//
//// NOTE: the original idea sheet had 6 args for a generic void version of
////	this function, but that 42 norm only allows 4 args per function, so
////	I made the decision to have a default cmp function for size_t and
////	ssize_t and only have a mapping function for the void * version.
////
////	PS: Yes you could make a struct to hold the args, yes you could make
////	a pointer to hold nb_elem, k and even flags, but that would be
////	a bit too unwieldy for the end-user.
////
//
// size_t *ft_bcksort(size_t *data, size_t nb_elem, size_t k,
//		int (*cmp)(size_t, size_t), int flags); // pb 5 args
// ssize_t *ft_bcksort(ssize_t *data, size_t nb_elem, size_t k,
//		int (*cmp)(ssize_t, ssize_t), int flags); // pb 5 args
// void **ft_bcksort(void **data, size_t nb_elem, size_t k,
//		size_t (*map)(const void *), t_data_cmp cmp, int flags); // pb 6 args
//
// choice-> default k to a log of nb_elem
// choice-> default cmp to ft_cmp_szt

#include "ft_sort.h"
#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include "ft_sort.h"
#include "ft_defs.h"
#include "ft_math.h"
#include "ft_mem.h"

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

static size_t	grab_max(size_t *collection, size_t nb_elem)
{
	size_t	max_val;
	size_t	i;

	max_val = collection[0];
	i = 0;
	while (i < nb_elem)
	{
		if (collection[i] > max_val)
			max_val = collection[i];
		i++;
	}
	return (max_val);
}

// bck -> array of k buckets
// bki -> indexes for each bucket
static void	collect_nbrs(size_t *data, size_t **bck, size_t *bki,
				size_t k)
{
	size_t	i;
	size_t	max_val;

	i = 0;
	max_val = 0;
	while (i < k)
	{
		ft_memcpy(&data[max_val], bck[i], bki[i] * sizeof(size_t));
		max_val += bki[i];
		i++;
	}
}

// TODO: optimize
//	- insertion sort for small buckets else quicksort
//	- optimize memory usage by using ft_vector instead of array allocated at
//		k * nb_elem
// NOTE: K might be better as a param?
size_t	*ft_sbcksort(size_t *data, size_t nb_elem, int flags)
{
	size_t			**buckets;
	const size_t	k = ft_ullogof((unsigned long long)nb_elem, 10) + 1;
	size_t			max_val;
	size_t			*bk_idx;
	size_t			i;

	if (nb_elem < 2 || k < 2)
		return (data);
	buckets = (size_t **)ft_aalloc(k, nb_elem, sizeof(size_t));
	bk_idx = ft_calloc(k, sizeof(size_t));
	if (!buckets || !bk_idx)
		return (ft_afree((void **)buckets), ft_free(bk_idx), data);
	max_val = grab_max(data, nb_elem);
	if (max_val != FT_SIZE_MAX)
		max_val += 1;
	i = 0;
	while (++i < nb_elem + 1)
		buckets[((data[i - 1] * k) / max_val) % k]
		[bk_idx[((data[i - 1] * k) / max_val) % k]++] = data[i - 1];
	i ^= i;
	while (i < k)
		if (bk_idx[i++] > 1)
			ft_sisrtsort(buckets[i - 1], bk_idx[i - 1], flags);
	collect_nbrs(data, buckets, bk_idx, k);
	return (ft_anfree((void **)buckets, k), ft_free(bk_idx), data);
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
