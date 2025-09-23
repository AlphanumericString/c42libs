/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_sis_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_stris.h"
#include "tests/str__str_sis_tests.h"

int	tsi_isnum(void)
{
	if (ft_str_isnum("-23") != true || ft_str_isnum("+42") != true
		|| ft_str_isnum("0") != true
		|| ft_str_isnum("2345865785645643532453") != true
		|| ft_str_isnum("2147483647") != true)
		return (1);
	if (ft_str_isnum("23.3") != false || ft_str_isnum("42.0") != false
		|| ft_str_isnum("0.0") != false || ft_str_isnum("2.000000") != false
		|| ft_str_isnum("0.000000") != false
		|| ft_str_isnum("--2147483648") != false
		|| ft_str_isnum("++2147483648") != false)
		return (2);
	if (ft_str_isnum("") != false || ft_str_isnum("+") != false
		|| ft_str_isnum("-") != false
		|| ft_str_isnum(NULL) != false)
		return (3);
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
