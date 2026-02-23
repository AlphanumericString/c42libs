/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:43:45 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 16:43:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_roundbuffer.h"
#include "ft_mem.h"

t_rb	*ftrb_create(t_rb *rb, size_t sz_elem, size_t nb_e)
{
	if (!rb || !sz_elem || !nb_e)
		return (NULL);
	rb->array = ft_malloc(sz_elem * nb_e);
	if (!rb->array)
		return (NULL);
	rb->sz_e = sz_elem;
	rb->nb_max = nb_e;
	rb->o_pos = 0;
	rb->i_pos = 0;
	return (rb);
}

t_rb	*ftrb_init(t_rb *rb, size_t sz_elem)
{
	return (ftrb_create(rb, sz_elem, PRB_NB_ELEM_DFLT));
}

t_rb	*ftrb_from_array(t_rb *rb, void *array, size_t nb_elem, size_t sz_elem)
{
	rb->i_pos = 0;
	rb->o_pos = 0;
	rb->sz_e = sz_elem;
	rb->nb_max = nb_elem;
	rb->array = array;
	return (rb);
}

t_rb	*ftrb_new(size_t sz_elem)
{
	t_rb	*ret;

	if (!sz_elem)
		return (NULL);
	ret = ft_malloc(sizeof(t_rb));
	if (ftrb_init(ret, sz_elem) == NULL)
		return (free(ret), NULL);
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
