/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:43:58 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 16:43:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_roundbuffer.h"
#include "ft_mem.h"

void	ftrb_push(t_rb *rb, const void *data)
{
	if (!rb)
		return ;
	ft_memcpy(rb->array + (rb->i_pos * rb->sz_e), data, rb->sz_e);
	if ((rb->i_pos + 1) % rb->nb_max == rb->o_pos)
	{
		rb->o_pos = (rb->o_pos + 1) % rb->nb_max;
	}
	rb->i_pos = (rb->i_pos + 1) % rb->nb_max;
}

void	ftrb_npush(t_rb *rb, const void *data, size_t n)
{
	if (!rb)
		return ;
	while (n > rb->nb_max)
	{
		data = (unsigned char *)data + (rb->nb_max * rb->sz_e);
		n -= rb->nb_max;
	}
	while (n)
		ftrb_push(rb, data);
}

bool	ftrb_push_safe(t_rb *rb, const void *data)
{
	if (!rb || (rb->i_pos + 1) % rb->nb_max == rb->o_pos)
		return (false);
	return (ftrb_push(rb, data), true);
}

bool	ftrb_npush_safe(t_rb *rb, const void *data, size_t n)
{
	size_t	i;

	if (!rb || n > rb->nb_max || (rb->i_pos + n) % rb->nb_max == rb->o_pos)
		return (false);
	i = 0;
	while (i < n)
		ftrb_push(rb, data + i * rb->sz_e);
	return (true);
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
