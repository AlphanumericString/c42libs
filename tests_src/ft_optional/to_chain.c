/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_chain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:28:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "types/ft_optional_types.h"
#include "tests/optional_tests.h"
#include "ft_defs.h"

int	to_chain(void)
{
	t_optional			opt;
	bool				ret;
	const t_data_tr_i	function_list[3] = {add_4, add_4, NULL };
	const t_data_tr_i	function_list2[3] = {add_fail, add_4, NULL };

	opt.pres = OPT_SOME;
	opt.val = (void *)42;
	ret = ft_optional_chain(&opt, function_list);
	if (ret != true || opt.pres != OPT_SOME || opt.val != (void *)42 + 8)
		return (1);
	opt.pres = OPT_NONE;
	ret = ft_optional_chain(&opt, function_list);
	if (ret != false || opt.pres != OPT_NONE)
		return (2);
	opt.pres = OPT_SOME;
	ret = ft_optional_chain(&opt, NULL);
	if (ret != false)
		return (3);
	opt.pres = OPT_SOME;
	ret = ft_optional_chain(&opt, function_list2);
	if (ret != false || opt.pres != OPT_NONE)
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
