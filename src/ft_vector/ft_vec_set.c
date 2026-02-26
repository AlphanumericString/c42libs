/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:27:39 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/24 19:27:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

static size_t	loc_abs(ssize_t i)
{
	if (i > 0)
		return ((size_t)i);
	return ((size_t)(i * -1));
}

bool	ft_vec_set(t_vector *vec, ssize_t pos, const void *data)
{
	if (!vec || loc_abs(pos) > vec->n_e)
		return (false);
	if (pos < 0)
		ft_memcpy(ft_vec_at(vec, vec->n_e - loc_abs(pos)), data, vec->s_e);
	else
		ft_memcpy(ft_vec_at(vec, loc_abs(pos)), data, vec->s_e);
	return (true);
}

bool	ft_vec_nset(t_vector *vec, ssize_t pos, size_t n, const void *datas)
{
	if (!vec || loc_abs(pos) + n > vec->n_e)
		return (false);
	if (pos < 0)
		ft_memcpy(ft_vec_at(vec, vec->n_e - loc_abs(pos)), datas, vec->s_e * n);
	else
		ft_memcpy(ft_vec_at(vec, loc_abs(pos)), datas, vec->s_e * n);
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
