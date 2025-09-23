/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_sis_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_stris.h"
#include "tests/str__str_sis_tests.h"

int	tsi_islong(void)
{
	if (ft_str_islong("23") != true || ft_str_islong("42") != true
		|| ft_str_islong("0") != true || ft_str_islong("2") != true
		|| ft_str_islong("-34") != true || ft_str_islong("42") != true
		|| ft_str_islong("9223372036854775807") != true
		|| ft_str_islong("-9223372036854775808") != true)
		return (1);
	if (ft_str_islong("9223372036854775808") != false
		|| ft_str_islong("-9223372036854775809") != false
		|| ft_str_islong("92233720368547758070") != false
		|| ft_str_islong("-92233720368547758080") != false
		|| ft_str_islong("9223372036854775807a") != false
		|| ft_str_islong("-9223372036854775808a") != false
		|| ft_str_islong("9223372036854775807 ") != false
		|| ft_str_islong("-9223372036854775808 ") != false
		|| ft_str_islong("-+0") != false || ft_str_islong("+-0") != false
		|| ft_str_islong("0-") != false || ft_str_islong("0+") != false)
		return (2);
	if (ft_str_islong("") != false || ft_str_islong("-") != false)
		return (3);
	if (ft_str_islong(NULL) != false)
		return (4);
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
