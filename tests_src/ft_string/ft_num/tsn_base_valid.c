/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsn_basevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:21:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/16 17:21:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__num_tests.h"
#include <stddef.h>

#define TLB "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

int	tsn_base_valid(void)
{
	const char	*ok_b[] = {FT_BINBASE, FT_DECBASE, FT_HEXBASE_CAP, FT_HEXBASE,
		"ab", "012345678x", "0123456789abcdeg"};
	const char	*no_b[] = {"01203", "azer12a", "", NULL, "1", "12+",
		TLB TLB TLB TLB TLB TLB TLB};
	size_t		i;

	i = 0;
	while (i < (sizeof(ok_b) / sizeof(ok_b[0])))
		if (ft_base_valid(ok_b[i++]) == false)
			return (i + 1);
	i = 0;
	while (i < (sizeof(no_b) / sizeof(no_b[0])))
		if (ft_base_valid(no_b[i++]) == true)
			return (i + (sizeof(ok_b) / sizeof(ok_b[0])) + 1);
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
