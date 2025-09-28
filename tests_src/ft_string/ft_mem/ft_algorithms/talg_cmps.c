/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_cmps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:21:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/22 21:21:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"

#include "tests/str__mem_tests.h"

static int	v_rcmps(void)
{
	const void	*v_set[] = {0x00, (void *)0xCAFE, (void *)0xDEAD,
		(void *)0xFFEE, (void *)0xFFFF};
	size_t		i;

	i = 0;
	while (++i < 5 - 1)
		if (ft_cmp_rptr(&v_set[i - 1], &v_set[i]) <= 0)
			return (1 * 10 + i);
	while (--i)
		if (ft_cmp_rptr(&v_set[i + 1], &v_set[i]) >= 0)
			return (2 * 10 + i);
	while (++i < 5)
		if (ft_cmp_rptr(&v_set[i], &v_set[i]) != 0)
			return (3 * 10);
	return (EXIT_SUCCESS);
}

static int	v_cmps(void)
{
	const void	*v_set[] = {0x00, (void *)0xCAFE, (void *)0xDEAD,
		(void *)0xFFEE, (void *)0xFFFF};
	size_t		i;

	i = 0;
	while (++i < 5 - 1)
		if (ft_cmp_ptr(&v_set[i - 1], &v_set[i]) >= 0)
			return (1 * 10 + i);
	while (--i)
		if (ft_cmp_ptr(&v_set[i + 1], &v_set[i]) <= 0)
			return (2 * 10 + i);
	while (++i < 5)
		if (ft_cmp_ptr(&v_set[i], &v_set[i]) != 0)
			return (3 * 10);
	return (EXIT_SUCCESS);
}

int	talg_cmps(void)
{
	const int		i_set[] = {-2147483648, 0, 2, 3, 2147483647};
	const size_t	s_set[] = {FT_SIZE_MIN, 12, 42, 45, FT_SIZE_MAX};
	const ssize_t	ss_set[] = {FT_SSIZE_MIN, 12, 42, 45, FT_SSIZE_MAX};
	size_t			i;

	i = 0;
	while (++i < 5 - 1)
		if (ft_cmp_int_p(&i_set[i - 1], &i_set[i]) >= 0
			|| ft_cmp_szt_p(&s_set[i - 1], &s_set[i]) >= 0
			|| ft_cmp_sszt_p(&ss_set[i - 1], &ss_set[i]) >= 0)
			return (1 * 10 + i);
	while (--i)
		if (ft_cmp_int_p(&i_set[i + 1], &i_set[i]) <= 0
			|| ft_cmp_szt_p(&s_set[i + 1], &s_set[i]) <= 0
			|| ft_cmp_sszt_p(&ss_set[i + 1], &ss_set[i]) <= 0)
			return (2 * 10 + i);
	while (++i < 5)
		if (ft_cmp_int_p(&i_set[i], &i_set[i]) != 0
			|| ft_cmp_szt_p(&s_set[i], &s_set[i]) != 0
			|| ft_cmp_sszt_p(&ss_set[i], &ss_set[i]) != 0)
			return (3 * 10 + i);
	return (v_cmps());
}

int	talg_rcmps(void)
{
	const int		i_set[] = {-2147483648, 0, 2, 3, 2147483647};
	const size_t	s_set[] = {FT_SIZE_MIN, 12, 42, 45, FT_SIZE_MAX};
	const ssize_t	ss_set[] = {FT_SSIZE_MIN, 12, 42, 45, FT_SSIZE_MAX};
	size_t			i;

	i = 0;
	while (++i < 5 - 1)
		if (ft_cmp_rint_p(&i_set[i - 1], &i_set[i]) <= 0
			|| ft_cmp_rszt_p(&s_set[i - 1], &s_set[i]) <= 0
			|| ft_cmp_rsszt_p(&ss_set[i - 1], &ss_set[i]) <= 0)
			return (1 * 10 + i);
	while (--i)
		if (ft_cmp_rint_p(&i_set[i + 1], &i_set[i]) >= 0
			|| ft_cmp_rszt_p(&s_set[i + 1], &s_set[i]) >= 0
			|| ft_cmp_rsszt_p(&ss_set[i + 1], &ss_set[i]) >= 0)
			return (2 * 10 + i);
	while (++i < 5)
		if (ft_cmp_rint_p(&i_set[i], &i_set[i]) != 0
			|| ft_cmp_rszt_p(&s_set[i], &s_set[i]) != 0
			|| ft_cmp_rsszt_p(&ss_set[i], &ss_set[i]) != 0)
			return (3 * 10 + i);
	return (v_rcmps());
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
