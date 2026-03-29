/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/28 22:28:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

static size_t	loc_abs(ssize_t i)
{
	if (i < 0)
		return ((size_t)(i * -1));
	return ((size_t)i);
}

size_t	ft_vec_inuse(const t_vector *vec)
{
	if (!vec)
		return (0);
	return (vec->n_e * vec->s_e);
}

// return elem n
void	*ft_vec_at(const t_vector *vec, ssize_t n)
{
	if (!vec || loc_abs(n) >= vec->n_e)
		return (NULL);
	if (n < 0)
		return (vec->data + (vec->s_e * ((ssize_t)vec->n_e + n)));
	return (vec->data + (vec->s_e * n));
}

void	*ft_vec_get(const t_vector *v, ssize_t n, void *e)
{
	const void	*e_src = ft_vec_at(v, n);

	if (e_src && e)
		return (ft_memcpy(e, e_src, v->s_e));
	return (NULL);
}

void	*ft_vec_nget(const t_vector *v, ssize_t pos, size_t n, void *holder)
{
	const void	*e_src;
	size_t		pos_abs;

	if (!v || !holder || !n)
		return (NULL);
	e_src = ft_vec_at(v, pos);
	if (!e_src)
		return (NULL);
	if (pos < 0)
		pos_abs = v->n_e + pos;
	else
		pos_abs = (size_t)pos;
	if (pos_abs + n > v->n_e)
		return (NULL);
	return (ft_memcpy(holder, e_src, v->s_e * n));
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
