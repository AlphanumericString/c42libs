/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_nrev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:05:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/18 10:39:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"
#include <stdio.h>

int	ts_nrev(void)
{
	const char	*str_hword_fwd = "Hello World!";
	const char	*str_hword_bwd = "!dlroW olleH";
	const char	*str_racecar = "racecar";
	char		str[32];
	char		palindrome[32];

	ft_strlcpy(str, str_hword_fwd, 32);
	ft_strlcpy(palindrome, str_racecar, 32);
	(ft_strnrev(palindrome, -1), ft_strnrev(str, -1));
	if (ft_strcmp(str, str_hword_bwd)
		|| str[ft_strlen(str_hword_fwd)] != '\0'
		|| ft_strcmp(palindrome, str_racecar))
		return (1);
	ft_strlcpy(str, str_hword_fwd, 32);
	(ft_strnrev(palindrome, 3), ft_strnrev(str, ft_strclen(str, ' ')));
	if (ft_strcmp("carecar", palindrome) != 0
		|| ft_strcmp("olleH World!", str) != 0)
		return (2);
	ft_strnrev(NULL, -1);
	ft_strnrev("", -1);
	ft_strnrev(str, 0);
	if (ft_strcmp("olleH World!", str) != 0)
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
