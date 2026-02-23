/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:43:21 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 16:43:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_roundbuffer.h"

// getters
bool	ftrb_full(t_rb rb)
{
	return (rb.o_pos == rb.i_pos + 1);
}

bool	ftrb_empty(t_rb rb)
{
	return (rb.i_pos == rb.o_pos);
}

size_t	ftrb_size(t_rb rb)
{
	if (rb.o_pos <= rb.i_pos)
		return (rb.i_pos - rb.o_pos);
	return ((rb.nb_max - rb.o_pos) + rb.i_pos);
}

size_t	ftrb_cappacity(t_rb rb)
{
	return (rb.nb_max);
}

size_t	ftrb_free(t_rb rb)
{
	return (ftrb_cappacity(rb) - ftrb_size(rb));
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
