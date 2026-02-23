/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:43:43 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 16:43:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_roundbuffer.h"
#include "ft_mem.h"

// INFO: the if checks if the number of dropped elements are either greater
// than the total number of elements
// or if the o_pos (output) + n arrives anywhere past the i_pos (input)
// if yes ->
//	calls clr to wip buffer
bool	ftrb_drop(t_rb *rb, size_t n)
{
	if (!rb || !n)
		return (false);
	if (n > rb->nb_max
		|| (rb->o_pos < rb->i_pos
			&& ((rb->o_pos + n) % rb->nb_max) > rb->i_pos)
		|| (rb->o_pos > rb->i_pos
			&& ((rb->o_pos + n) % rb->nb_max) < rb->i_pos))
	{
		return (ftrb_clr(rb), true);
	}
	rb->o_pos = (rb->o_pos + n) % rb->nb_max;
	return (true);
}

void	*ftrb_peek(t_rb rb, void *elem_out)
{
	unsigned char	*pos;

	pos = rb.array + (rb.o_pos * rb.sz_e);
	if (elem_out)
		ft_memcpy(elem_out, pos, rb.sz_e);
	return (pos);
}

void	*ftrb_npeek(t_rb rb, size_t n, void *elem_out)
{
	unsigned char	*pos;
	size_t			left_size;

	if (!n)
		return (NULL);
	if (n > rb.nb_max)
		n = rb.nb_max;
	if (n > ftrb_size(rb))
		n = ftrb_size(rb);
	pos = rb.array + (rb.o_pos * rb.sz_e);
	if (elem_out)
	{
		if (rb.nb_max > (rb.o_pos + n))
			ft_memcpy(elem_out, pos, n * rb.sz_e);
		else
		{
			left_size = (rb.nb_max - rb.o_pos) * rb.sz_e;
			ft_memcpy(elem_out, pos, left_size);
			n -= rb.nb_max - rb.o_pos;
			pos = rb.array;
			ft_memcpy(elem_out + left_size, pos, n * rb.sz_e);
		}
	}
	return (pos);
}

void	*ftrb_pop(t_rb *rb, void *elem_out)
{
	void	*return_val;

	if (!rb)
		return (NULL);
	return_val = ftrb_peek(*rb, elem_out);
	rb->o_pos = (rb->o_pos + 1) % rb->nb_max;
	return (return_val);
}

void	*ftrb_npop(t_rb *rb, size_t n, void *elem_out)
{
	void	*return_val;

	if (!rb)
		return (NULL);
	return_val = ftrb_npeek(*rb, n, elem_out);
	if (n > ftrb_size(*rb))
		n = ftrb_size(*rb);
	rb->o_pos = (rb->o_pos + n) % rb->nb_max;
	return (return_val);
}

// // NOTE: might be usefull for certain algorithms
// // (rb.o_pos - rb.nb_max + n) > rb.i_pos)
// // calc with arr=[i_pos 0 1 o_pos] n=2
// // o_pos - 4 + 2 > 0 ?
// // 3-4+2 > 0
// // 1 > 0
// static bool would_cross(t_rb rb, size_t n) {
// 	if ((rb.o_pos < rb.i_pos && (rb.o_pos + n) > rb.i_pos) ||
// 	    (rb.o_pos > rb.i_pos && (rb.o_pos - rb.nb_max + n) > rb.i_pos))
// 		return (true);
// 	return (false);
// }
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
