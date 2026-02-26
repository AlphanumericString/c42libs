/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:53:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:45 by bgoulard         ###   ########.fr       */
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

void	ft_vec_swap(t_vector *vec, ssize_t a, ssize_t b)
{
	if (!vec || !vec->s_e || !vec->n_e)
		return ;
	if (loc_abs(a) >= vec->n_e || loc_abs(b) >= vec->n_e)
		return ;
	ft_swap(ft_vec_at(vec, a), ft_vec_at(vec, b), vec->s_e);
}

void		ft_vec_nswap(t_vector *vec, size_t n, ssize_t a, ssize_t b)
{
	if (!vec || !vec->s_e || !vec->n_e || !n)
		return ;
	if (n >= vec->n_e)
		return ;
	if (loc_abs(a) + n >= vec->n_e || loc_abs(b) + n >= vec->n_e)
		return ;
	ft_swap(ft_vec_at(vec, a), ft_vec_at(vec, b), vec->s_e * n);
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
