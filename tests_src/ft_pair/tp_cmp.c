/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:20:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_algorithms.h"
#include "types/ft_pair_types.h"
#include "tests/pair_tests.h"
#include "tests/tests_lambda_functions.h"
#include "tests/pair_tests.h"

static int	test_ptr(void)
{
	t_pair	pair_a;
	t_pair	pair_b;
	t_pair	pair_c;

	triple_pair_setup(&pair_a, &pair_b, &pair_c);
	if (ft_pair_cmp(&pair_a, &pair_b, NULL) == 0
		|| ft_pair_cmp(&pair_b, &pair_a, NULL) == 0)
		return (1);
	if (ft_pair_cmp(&pair_a, &pair_a, NULL) != 0
		|| ft_pair_cmp(&pair_c, &pair_a, NULL) != 0
		|| ft_pair_cmp(&pair_a, &pair_c, NULL) != 0
		|| ft_pair_cmp(NULL, NULL, NULL) != 0)
		return (2);
	if (ft_pair_cmp(NULL, &pair_a, NULL) == 0
		|| ft_pair_cmp(&pair_a, NULL, NULL) == 0)
		return (4);
	return (EXIT_SUCCESS);
}

static int	test_cmp(void)
{
	t_pair	pair_a;
	t_pair	pair_b;
	t_pair	pair_c;

	triple_pair_setup(&pair_a, &pair_b, &pair_c);
	if (ft_pair_cmp(&pair_a, &pair_b, &ft_cmp_int_p) == 0)
		return (1);
	if (ft_pair_cmp(&pair_a, &pair_c, &ft_cmp_int_p) != 0)
		return (2);
	return (EXIT_SUCCESS);
}

int	tp_cmp(void)
{
	int	ret;

	ret = test_ptr();
	if (ret != 0)
		return (ret);
	ret = test_cmp();
	if (ret != 0)
		return (ret + 10);
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
