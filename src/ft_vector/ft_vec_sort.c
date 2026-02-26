/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include "ft_defs.h"
#include "ft_vector.h"

void	ft_vec_sort(t_vector *vec, t_data_cmp cmp_f)
{
	if (!vec || !cmp_f)
		return ;
	return (ft_vec_nsort(vec, -1, cmp_f));
}

void	ft_vec_nsort(t_vector *vec, size_t n, t_data_cmp cmp_f)
{
	if (!vec)
		return ;
	if (n > vec->n_e)
		n = vec->n_e;
	ft_qsort(vec->data, n, vec->s_e, cmp_f);
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
