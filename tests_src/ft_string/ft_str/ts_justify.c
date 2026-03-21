/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:23:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/05 20:23:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/fixtures.h"
#include "tests/str__str_tests.h"
#include "ft_string.h"
#include "ft_mem.h"

static int	mt_jstfy_nospace(void)
{
	char		*str;
	const int	fp = *talloc_get_failpoint();

	talloc_set_failpoint(0);
	str = ft_strwlgn_nospace("Hello this is a test string.", 11);
	talloc_set_failpoint(fp);
	if (str != NULL)
		return (ft_free(str), 6);
	return (EXIT_SUCCESS);
}

int	ts_justify_inplace(void)
{
	char		str1[64];
	const char	*exp = "Hello this\x0ais a test\x0astring.";
	const char	*src[] = {"Hello this is a test string.",
		"Hello this                       is a         test string.", " ",
		" \t\tfaaart... oupsi\t"};

	ft_bzero(str1, sizeof(str1));
	ft_strlcpy(str1, src[0], sizeof(str1));
	if (ft_strwlgn_inplace(str1, 11) != str1 || ft_strcmp(str1, exp) != 0)
		return (1);
	ft_strlcpy(str1, src[1], sizeof(str1));
	if (ft_strwlgn_inplace(str1, 11) != str1 || ft_strcmp(str1, exp) != 0)
		return (2);
	ft_strlcpy(str1, src[2], sizeof(str1));
	if (ft_strwlgn_inplace(str1, 11) != str1 || ft_strcmp(str1, "") != 0)
		return (3);
	ft_strlcpy(str1, src[3], sizeof(str1));
	if (ft_strwlgn_inplace(str1, 11) != str1
		|| ft_strcmp(str1, "Faaart...\nOupsi") != 0)
		return (4);
	if (ft_strwlgn_inplace(NULL, 10) != NULL)
		return (5);
	return (EXIT_SUCCESS);
}

int	ts_justify_nospace(void)
{
	char		*str;
	const char	*exp = "Hello this\x0ais a test\x0astring.";
	const char	*src[] = {"Hello this is a test string.",
		"Hello this                       is a         test string.", " ",
		" \t\tfaaart... oupsi\t"};

	str = ft_strwlgn_nospace(src[0], 11);
	if (!str || ft_strcmp(str, exp) != 0)
		return (ft_free(str), 1);
	str = (ft_free(str), ft_strwlgn_nospace(src[1], 11));
	if (!str || ft_strcmp(str, exp) != 0)
		return (ft_free(str), 2);
	str = (ft_free(str), ft_strwlgn_nospace(src[2], 11));
	if (!str || ft_strcmp(str, "") != 0)
		return (ft_free(str), 3);
	str = (ft_free(str), ft_strwlgn_nospace(src[3], 11));
	if (!str || ft_strcmp(str, "Faaart...\nOupsi") != 0)
		return (ft_free(str), 4);
	str = (ft_free(str), ft_strwlgn_nospace(NULL, 10));
	if (str != NULL)
		return (5);
	return (mt_jstfy_nospace());
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
