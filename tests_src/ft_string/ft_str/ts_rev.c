/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:05:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/18 12:48:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_rev(void)
{
	const char	*str_ref = "Hello World!";
	const char	*str_ref_rev = "!dlroW olleH";
	const char	*str_ref2 = "racecar";
	char		str[32];
	char		palindrome[32];

	ft_strlcpy(str, str_ref, 32);
	ft_strlcpy(palindrome, str_ref2, 32);
	ft_strrev(str);
	if (ft_strcmp(str, str_ref_rev))
		return (1);
	if (str[ft_strlen(str_ref)] != '\0')
		return (2);
	ft_strrev(palindrome);
	if (ft_strcmp(palindrome, str_ref2))
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
