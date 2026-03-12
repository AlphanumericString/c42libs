/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:16:44 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/26 14:16:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

int	ft_vec_cmp(const t_vector *a, const t_vector *b, t_data_cmp fc)
{
	return (ft_vec_ncmp(a, -1, b, fc));
}

int	ft_vec_ncmp(const t_vector *a, size_t n, const t_vector *b, t_data_cmp fc)
{
	size_t	i;
	int		r;

	if (a == b || !n)
		return (0);
	if (!b)
		return (1);
	if (!a)
		return (-1);
	if (n > a->n_e)
		n = a->n_e;
	i = 0;
	while (i < n)
	{
		if (fc)
			r = fc(ft_vec_at(a, i), ft_vec_at(b, i));
		else
			r = ft_memcmp(ft_vec_at(a, i), ft_vec_at(b, i), a->s_e);
		if (r)
			return (r);
		i++;
	}
	return (0);
}

int	ft_vec_acmp(const t_vector *a, const void *b, t_data_cmp fc)
{
	return (ft_vec_ancmp(a, -1, b, fc));
}

int	ft_vec_ancmp(const t_vector *a, size_t n, const void *b, t_data_cmp fc)
{
	size_t	i;
	int		r;

	if (!a && !b)
		return (0);
	if (!a)
		return (1);
	if (!b)
		return (-1);
	if (n > a->n_e)
		n = a->n_e;
	i = 0;
	while (i < n)
	{
		if (fc)
			r = fc(ft_vec_at(a, i), ((char *)b) + i * a->s_e);
		else
			r = ft_memcmp(ft_vec_at(a, i), ((char *)b) + i * a->s_e, a->s_e);
		if (r)
			return (r);
		i++;
	}
	return (0);
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
