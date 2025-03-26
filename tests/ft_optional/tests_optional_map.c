/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_optional_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:31:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_optional.h"
#include "ft_optional_types.h"
#include "tests/optional_test.h"
#include "tests/tests__all_modules_tests.h"

int	test_optional_map(void)
{
	t_optional			opt;
	t_optional			ret;
	const t_data_tr_i	f_list[] = {add_4, add_4, NULL };

	opt.pres = OPT_SOME;
	opt.val = (void *)42;
	ret = ft_optional_map(&opt, (t_data_tr_i *)f_list);
	if (ret.pres != OPT_SOME)
		return (1);
	if (ret.val != (void *)42 + 8)
		return (2);
	if (ft_optional_map(&opt, NULL).pres != OPT_NONE)
		return (3);
	opt.pres = OPT_NONE;
	if (ft_optional_map(&opt, (t_data_tr_i *)f_list).pres != OPT_NONE)
		return (4);
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
