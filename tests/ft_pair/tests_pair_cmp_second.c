/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pair_cmp_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:19:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include "ft_string.h"
#include "tests/pair_tests.h"
#include "tests/tests__all_modules_tests.h"

static int	test_ptr(void)
{
	t_pair	pair;
	t_pair	pair_b;
	void	*a;
	void	*b;
	void	*c;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADCAFE;
	c = (void *)0xDEADDEAD;
	pair_b.second = c;
	ft_pair_set(&pair, b, b);
	if (ft_pair_cmp_second(&pair, &pair_b, NULL) >= 0)
		return (1);
	pair_b.second = b;
	if (ft_pair_cmp_second(&pair, &pair_b, NULL) != 0)
		return (2);
	pair_b.second = a;
	if (ft_pair_cmp_second(&pair, &pair_b, NULL) <= 0)
		return (3);
	if (ft_pair_cmp_second(&pair, NULL, NULL) == 0 || ft_pair_cmp_second(NULL,
			&pair, NULL) == 0)
		return (4);
	if (ft_pair_cmp_second(NULL, NULL, NULL) != 0)
		return (5);
	return (0);
}

static int	test_cmp(void)
{
	t_pair		pair_a;
	t_pair		pair_b;
	const char	*a = "a";
	const char	*b = "b";
	const char	*c = "c";

	ft_pair_set(&pair_a, (void *)a, (void *)b);
	ft_pair_set(&pair_b, (void *)c, (void *)a);
	if (ft_pair_cmp_second(&pair_a, &pair_b, (t_data_cmp) & ft_strcmp) == 0)
		return (1);
	return (0);
}

int	tp_cmp_second(void)
{
	int	ret;

	ret = test_ptr();
	if (ret != 0)
		return (ret);
	ret = test_cmp();
	if (ret != 0)
		return (ret);
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
