/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:20:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_mem.h"
#include "tests/fixtures.h"
#include "tests/str__mem_tests.h"
#include "ft_string.h"

#define T_SIZE	64

static int	tm_swap_unaligned_tests_nooverlaps(void)
{
	const char	*srca = "Hello This is a String";
	const char	*srcb = "Good bye this b String";
	char		stra[T_SIZE];
	char		strb[T_SIZE];

	(ft_strlcpy(stra, srca, T_SIZE), ft_strlcpy(strb, srcb, T_SIZE));
	ft_swap_xor(stra + 2, strb, ft_strlen(stra + 2));
	if (ft_strcmp(stra, "HeGood bye this b Stri")
		|| ft_strcmp(strb, "llo This is a Stringng"))
		return (1);
	(ft_strlcpy(stra, srca, T_SIZE), ft_strlcpy(strb, srcb, T_SIZE));
	ft_swap_xor(stra, strb + 2, ft_strlen(strb + 2));
	if (ft_strcmp(stra, "od bye this b Stringng")
		|| ft_strcmp(strb, "GoHello This is a Stri"))
		return (2);
	ft_swap_xor(stra + 2, strb, 2);
	if (ft_strncmp(stra, "odGoye", 5) || ft_strncmp(strb, " bHello", 5))
		return (3);
	return (EXIT_SUCCESS);
}

int	tm_swap_xor(void)
{
	const char	*srca = "Hello This is a String";
	const char	*srcb = "Good bye this b String";
	char		stra[T_SIZE];
	char		strb[T_SIZE];
	int			i;

	i = 0;
	while (i < ft_min(ft_strlen(srca), T_SIZE))
	{
		(ft_strlcpy(stra, srca, T_SIZE), ft_strlcpy(strb, srcb, T_SIZE));
		ft_swap_xor(stra + i, strb + i, ft_strlen(stra + i));
		if (ft_strcmp(stra + i, srcb + i) || ft_strcmp(strb + i, srca + i))
			return (1 + i);
		i++;
	}
	(ft_swap_xor(stra, NULL, 4), ft_swap_xor(NULL, stra, 4),
		ft_swap_xor(NULL, NULL, 4));
	i = tm_swap_unaligned_tests_nooverlaps();
	return (i);
}

static int	mt_swap_alloc(void)
{
	char		*tmpa;
	char		*tmpb;
	const int	fp = *talloc_get_failpoint();
	int			ret;

	tmpa = (t_any)0xDEaD;
	tmpb = (t_any)0xCaFE;
	ret = EXIT_SUCCESS;
	talloc_set_failpoint(0);
	ft_swap(tmpa, tmpb, FT_LARGE_BUF_SIZE);
	talloc_set_failpoint(fp);
	return (ret);
}

int	tm_swap(void)
{
	const char	*srca = "Hello This is a String";
	const char	*srcb = "Good bye this b String";
	char		stra[T_SIZE];
	char		strb[T_SIZE];

	ft_strlcpy(stra, srca, T_SIZE);
	ft_strlcpy(strb, srcb, T_SIZE);
	ft_swap(stra, strb, ft_strlen(stra));
	if (ft_strcmp(stra, srcb) != 0 || ft_strcmp(strb, srca) != 0)
		return (1);
	(ft_strlcpy(stra, srca, T_SIZE), ft_strlcpy(strb, srcb, T_SIZE));
	ft_swap(stra + 2, stra, 4);
	if (ft_strncmp(stra, "llo ll", 6) != 0)
		return (2);
	(ft_strlcpy(stra, srca, T_SIZE), ft_strlcpy(strb, srcb, T_SIZE));
	(ft_swap(stra, strb, 0), ft_swap(stra, stra, 4));
	(ft_swap(stra, NULL, 4), ft_swap(NULL, stra, 4), ft_swap(NULL, NULL, 4));
	ft_swap(strb, strb, T_SIZE);
	if (ft_strcmp(stra, srca) != 0)
		return (3);
	return (mt_swap_alloc());
}

int	tm_swap_ptr(void)
{
	const int	pair_og[2] = {1, 2};
	const int	*pair[2];
	const int	*pair2[2] = {&pair_og[1], &pair_og[0]};

	pair[0] = &pair_og[0];
	pair[1] = &pair_og[1];
	ft_swap_ptr((void **)&pair[0], (void **)&pair[1]);
	if (pair[0] != pair2[0] || pair[1] != pair2[1])
		return (1);
	return (EXIT_SUCCESS);
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
