/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 06:16:26 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/11 01:09:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

// NOTE: vec->n_e++ before manip for vec_at not to fail to null on bad access
bool	ft_vec_insert(t_vector *vec, size_t pos, const void *elem)
{
	if (!vec || !vec->data || !vec->n_e || !vec->s_e || !elem)
		return (false);
	if (pos >= vec->n_e)
		return (ft_vec_add(vec, elem));
	if ((vec->n_e + 1) > vec->cappacity)
		if (ft_vec_reserve(vec, 1) != true)
			return (false);
	vec->n_e++;
	ft_memmove(ft_vec_at(vec, pos + 1), ft_vec_at(vec, pos),
		vec->s_e * (vec->n_e - pos - 1));
	ft_memcpy(ft_vec_at(vec, pos), elem, vec->s_e);
	return (true);
}

bool	ft_vec_ninsert(t_vector *vec, size_t pos, size_t n, const void *elems)
{
	if (!vec || !vec->data || !vec->n_e || !vec->s_e || !elems)
		return (false);
	if (!n)
		return (true);
	if (pos >= vec->n_e)
		return (ft_vec_nadd(vec, n, elems));
	if ((vec->n_e + n) >= vec->cappacity)
		if (ft_vec_reserve(vec, n) != true)
			return (false);
	vec->n_e += n;
	ft_memmove(ft_vec_at(vec, pos + n), ft_vec_at(vec, pos),
		vec->s_e * (vec->n_e - pos));
	ft_memcpy(ft_vec_at(vec, pos), elems, vec->s_e * n);
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
