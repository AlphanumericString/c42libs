/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:04:21 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/24 20:04:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

t_vector	*ft_vec_init(t_vector *v, size_t n, size_t s)
{
	size_t	cap;
	void	*d;

	*v = (t_vector){0};
	cap = n;
	if (cap < FT_VECTOR_BASE_LEN)
		cap = FT_VECTOR_BASE_LEN;
	d = ft_malloc(s * cap);
	if (!d)
		return (NULL);
	*v = (t_vector){.s_e = s, .n_e = 0, .cappacity = cap, .data = d};
	return (v);
}

t_vector	*ft_vec_ifrom_array(t_vector *v, const void *a, size_t n, size_t s)
{
	void	*d;

	if (!v || !a || !s || !n)
		return (NULL);
	d = ft_malloc(n * s);
	if (!d)
		return (NULL);
	ft_memcpy(d, a, n * s);
	return (ft_vec_iconvert_allocarray(v, d, n, s));
}

t_vector	*ft_vec_iconvert_allocarray(t_vector *v, void *d, size_t n,
				size_t s)
{
	if (!v)
		return (NULL);
	*v = (t_vector){0};
	if (!s || !n || !d)
		return (NULL);
	*v = (t_vector){.s_e = s, .n_e = n, .cappacity = n, .data = d};
	return (v);
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
