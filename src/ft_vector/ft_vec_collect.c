/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:05:48 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/24 19:05:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vec_collect(const t_vector *v, void *u_val, t_data_apply_with fw)
{
	return (ft_vec_ncollect(v, -1, u_val, fw));
}

void	*ft_vec_ncollect(const t_vector *v, size_t n, void *u_val,
			t_data_apply_with fw)
{
	size_t	i;

	if (!v || !fw || !n)
		return (u_val);
	if (n > v->n_e)
		n = v->n_e;
	i = 0;
	while (i < n)
		fw(u_val, ft_vec_at(v, i++));
	return (u_val);
}

void	*ft_vec_ncollect_r(const t_vector *v, size_t n, void *u_val,
		t_data_apply_with fw)
{
	size_t	i;

	if (!v || !fw || !n)
		return (u_val);
	i = n;
	if (i > v->n_e)
		i = v->n_e;
	while (i)
		fw(u_val, ft_vec_at(v, i--));
	return (u_val);
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
