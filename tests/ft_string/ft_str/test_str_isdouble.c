/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isdouble.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 14:53:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"
#include <stddef.h>
#include <stdio.h>

int	test_str_isdouble(void)
{
	size_t		i;
	const char	*valid_str[20] = {
		"23.3", "42", "0.0", "2.0000", "0.00000", "+0e+00", "43.32e-12", NULL};
	const char	*err_str[20] = {
		"34..4", "0a.0", "a0.0", "0.0a", "0a0", "0.a0", "1.0.0", "0.0.0",
		"+.", "+", "-", ".", "++0", "+-32.12e+12", "", NULL};

	i = 0;
	while (valid_str[i])
		if (ft_str_isdouble(valid_str[i++]) != true)
			return (i);
	i = 0;
	while (err_str[i])
		if (ft_str_isdouble(err_str[i++]) != false)
			return (20 + i);
	if (ft_str_isdouble(NULL) != false)
		return (40);
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
