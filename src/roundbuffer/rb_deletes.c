/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_deletes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:43:55 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 16:43:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_roundbuffer.h"
#include "ft_mem.h"

void	ftrb_destroy(t_rb *rb)
{
	if (!rb)
		return ;
	if (rb->array)
		ft_free(rb->array);
	*rb = (t_rb){0};
}

void	ftrb_clr(t_rb *rb)
{
	if (!rb)
		return ;
	rb->o_pos = 0;
	rb->i_pos = rb->o_pos;
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
