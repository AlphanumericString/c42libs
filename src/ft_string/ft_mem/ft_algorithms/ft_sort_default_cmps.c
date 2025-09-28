/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_default_cmps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:19:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/07 23:19:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include <stddef.h>
#include <stdio.h>

int	ft_cmp_ptr(const void *a, const void *b)
{
	return (ft_cmp_szt_p((size_t *)&a, (size_t *)&b));
}

int	ft_cmp_int_p(const void *a, const void *b)
{
	const bool	eq = *(int *)a == *(int *)b;
	bool		lt;

	if (eq)
		return (0);
	lt = *(int *)a < *(int *)b;
	if (lt)
		return (-1);
	return (1);
}

int	ft_cmp_szt_p(const void *a, const void *b)
{
	const bool	eq = *(size_t *)a == *(size_t *)b;
	bool		lt;

	if (eq)
		return (0);
	lt = *(size_t *)a < *(size_t *)b;
	if (lt)
		return (-1);
	return (1);
}

int	ft_cmp_sszt_p(const void *a, const void *b)
{
	const bool	eq = *(ssize_t *)a == *(ssize_t *)b;
	bool		lt;

	if (eq)
		return (0);
	lt = *(ssize_t *)a < *(ssize_t *)b;
	if (lt)
		return (-1);
	return (1);
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
