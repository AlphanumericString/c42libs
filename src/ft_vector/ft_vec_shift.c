/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

void	ft_vec_shift(t_vector *vec, size_t start, size_t shift)
{
	if (!vec)
		return ;
	if (!vec->n_e || !vec->s_e || start >= vec->n_e || !shift)
		return ;
	if (start + shift >= vec->n_e)
		return (vec->n_e = start, (void) 0);
	ft_memmove(ft_vec_at(vec, start), ft_vec_at(vec, start + shift),
		(vec->n_e - start - shift) * vec->s_e);
	vec->n_e -= shift;
}

bool	ft_vec_advance(t_vector *v, size_t n)
{
	if (!v || !n)
		return (false);
	if (v->n_e <= n)
		return (ft_vec_clear(v), true);
	ft_memmove(ft_vec_at(v, 0), ft_vec_at(v, n), (v->n_e - n) * v->s_e);
	v->n_e -= n;
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
