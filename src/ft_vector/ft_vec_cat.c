/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:40:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

bool	ft_vec_cat(t_vector *dst, const t_vector *src)
{
	bool	ret;

	if (!dst || !src || dst->s_e != src->s_e)
		return (false);
	ret = ft_vec_reserve(dst, src->n_e);
	if (!ret)
		return (false);
	ft_memcpy(dst->data + ft_vec_inuse(dst), src->data, ft_vec_inuse(src));
	dst->n_e += src->n_e;
	return (true);
}

bool		ft_vec_ncat(t_vector *dst, const t_vector *src, size_t n)
{
	bool	ret;

	if (!dst || !src || !n || dst->n_e != src->n_e)
		return (false);
	if (n > dst->n_e)
		n = dst->n_e;
	ret = ft_vec_reserve(dst, n);
	if (!ret)
		return (false);
	ft_memcpy(dst->data + ft_vec_inuse(dst), src->data, src->s_e * n);
	dst->n_e += n;
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
