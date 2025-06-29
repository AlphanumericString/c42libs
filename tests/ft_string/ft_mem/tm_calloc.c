/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:23:35 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"
#include <stdint.h>

// str[x] = 'a' is to test that we can write in the memory we asked for
int	tm_calloc(void)
{
	char	*str;

	str = ft_calloc(10, sizeof(char));
	str[9] = 'a';
	ft_free(str);
	str = ft_calloc(10, sizeof(char *));
	str[9 * sizeof(char *)] = 'a';
	ft_free(str);
	str = ft_calloc(0, sizeof(char));
	ft_free(str);
	str = ft_calloc(SIZE_MAX, SIZE_MAX);
	if (str)
		return (1);
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
