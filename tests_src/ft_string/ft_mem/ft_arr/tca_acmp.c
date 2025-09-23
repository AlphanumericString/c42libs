/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_acmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

int	tca_acmp(void)
{
	const char	*arr1[] = {"a", "b", NULL};
	const char	*arr2[] = {"a", "b", NULL};
	const char	*arr3[] = {"a", "b", "42", NULL};
	const char	*arr4[] = {"a", "a", NULL};

	if (ft_acmp((t_iconst_arr) NULL, (t_iconst_arr) NULL) != 0
		|| ft_acmp((t_iconst_arr)arr1, (t_iconst_arr)arr1) != 0
		|| ft_acmp((t_iconst_arr)arr1, (t_iconst_arr)arr2) != 0)
		return (1);
	if (ft_acmp((t_iconst_arr)arr3, (t_iconst_arr)arr1) < 0
		|| ft_acmp((t_iconst_arr)arr1, (t_iconst_arr)arr3) > 0)
		return (3);
	if (ft_acmp((t_iconst_arr)arr3, (t_iconst_arr) NULL) < 0
		|| ft_acmp((t_iconst_arr) NULL, (t_iconst_arr)arr3) > 0)
		return (4);
	if (ft_acmp((t_iconst_arr)arr1, (t_iconst_arr)arr4) == 0
		|| ft_acmp((t_iconst_arr)arr4, (t_iconst_arr)arr1) == 0)
		return (5);
	return (EXIT_SUCCESS);
}

int	tca_ancmp(void)
{
	const char	*arr1[] = {"a", "b", NULL};
	const char	*arr2[] = {"a", "b", NULL};
	const char	*arr3[] = {"a", "b", "42", NULL};
	const char	*arr4[] = {"a", "a", NULL};

	if (ft_ancmp((t_iconst_arr) NULL, (t_iconst_arr) NULL, 0) != 0
		|| ft_ancmp((t_iconst_arr)arr1, (t_iconst_arr)arr1, 0) != 0
		|| ft_ancmp((t_iconst_arr)arr1, (t_iconst_arr)arr2, 0) != 0
		|| ft_ancmp((t_iconst_arr)arr1, (t_iconst_arr)arr1, 2) != 0
		|| ft_ancmp((t_iconst_arr)arr1, (t_iconst_arr)arr3, 2) != 0
		|| ft_ancmp((t_iconst_arr) NULL, (t_iconst_arr) NULL, 2) != 0
		|| ft_ancmp((t_iconst_arr)arr4, (t_iconst_arr)arr1, 1) != 0)
		return (1);
	if (ft_ancmp((t_iconst_arr)arr3, (t_iconst_arr)arr1, 3) == 0
		|| ft_ancmp((t_iconst_arr)arr1, (t_iconst_arr)arr3, 3) == 0
		|| ft_ancmp((t_iconst_arr)arr4, (t_iconst_arr)arr3, 42) == 0
		|| ft_ancmp((t_iconst_arr)arr3, (t_iconst_arr)arr4, 42) == 0
		|| ft_ancmp((t_iconst_arr)arr1, (t_iconst_arr)arr3, 42) == 0
		|| ft_ancmp((t_iconst_arr)arr3, (t_iconst_arr)arr1, 42) == 0
		|| ft_ancmp((t_iconst_arr)arr3, (t_iconst_arr) NULL, 2) == 0
		|| ft_ancmp((t_iconst_arr) NULL, (t_iconst_arr) arr3, 2) == 0)
		return (2);
	return (EXIT_SUCCESS);
}

int	tca_acmpwith(void)
{
	const char	*arr1[] = {"hello", "42", NULL};
	const char	*arr2[] = {"hello", "42", NULL};
	const char	*arr3[] = {"hi", "21", NULL};
	const char	*arr4[] = {"hello", "42", "toto", NULL};

	if (ft_acmp_with((t_const_arr)arr1, (t_const_arr)arr1, NULL) != 0
		|| ft_acmp_with((t_const_arr)arr1, (t_const_arr)arr2,
			(t_data_cmp)ft_strcmp) != 0)
		return (2);
	if (ft_acmp_with((t_const_arr)arr1, (t_const_arr)arr3,
			(t_data_cmp)ft_strcmp) == 0
		|| ft_acmp_with((t_const_arr)arr3, (t_const_arr)arr1,
			(t_data_cmp)ft_strcmp) == 0)
		return (3);
	if (ft_acmp_with((t_const_arr)arr1, (t_const_arr)arr4,
			(t_data_cmp)ft_strcmp) >= 0
		|| ft_acmp_with((t_const_arr)arr4, (t_const_arr)arr1,
			(t_data_cmp)ft_strcmp) <= 0)
		return (4);
	if (ft_acmp_with(NULL, (t_const_arr)arr1, NULL) >= 0
		|| ft_acmp_with((t_const_arr)arr1, NULL, NULL) <= 0)
		return (5);
	return (EXIT_SUCCESS);
}

int	tca_ancmpwith(void)
{
	const char	*arr1[] = {"a", "b", NULL};
	const char	*arr2[] = {"a", "b", NULL};
	const char	*arr3[] = {"a", "b", "42", NULL};
	const char	*arr4[] = {"a", "a", NULL};

	if (ft_ancmp_with((t_any) NULL, (t_any) NULL, 0, (t_any)ft_strcmp) != 0
		|| ft_ancmp_with((t_any)arr1, (t_any)arr1, 0, (t_any)ft_strcmp) != 0
		|| ft_ancmp_with((t_any)arr1, (t_any)arr2, 0, (t_any)ft_strcmp) != 0
		|| ft_ancmp_with((t_any)arr1, (t_any)arr1, 2, (t_any)ft_strcmp) != 0
		|| ft_ancmp_with((t_any)arr1, (t_any)arr3, 2, (t_any)ft_strcmp) != 0
		|| ft_ancmp_with((t_any) NULL, (t_any) NULL, 2, (t_any)ft_strcmp) != 0
		|| ft_ancmp_with((t_any)arr4, (t_any)arr1, 1, (t_any)ft_strcmp) != 0
		|| ft_ancmp_with((t_any)arr4, (t_any)arr1, 1, NULL) != 0)
		return (1);
	if (ft_ancmp_with((t_any)arr3, (t_any)arr1, 3, (t_any)ft_strcmp) == 0
		|| ft_ancmp_with((t_any)arr1, (t_any)arr3, 3, (t_any)ft_strcmp) == 0
		|| ft_ancmp_with((t_any)arr4, (t_any)arr3, 42, (t_any)ft_strcmp) == 0
		|| ft_ancmp_with((t_any)arr3, (t_any)arr4, 42, (t_any)ft_strcmp) == 0
		|| ft_ancmp_with((t_any)arr1, (t_any)arr3, 42, (t_any)ft_strcmp) == 0
		|| ft_ancmp_with((t_any)arr3, (t_any)arr1, 42, (t_any)ft_strcmp) == 0
		|| ft_ancmp_with((t_any)arr3, (t_any) NULL, 2, (t_any)ft_strcmp) == 0
		|| ft_ancmp_with((t_any) NULL, (t_any) arr3, 2, (t_any)ft_strcmp) == 0)
		return (2);
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
