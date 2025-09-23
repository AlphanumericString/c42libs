/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stricmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:07:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/10 11:07:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"

static int	cmp_ic(int char_a, int char_b)
{
	char_a = ft_tolower(char_a);
	char_b = ft_tolower(char_b);
	return (char_a - char_b);
}

int	ft_stricmp(const char *restrict s1, const char *restrict s2)
{
	return (ft_strnicmp(s1, s2, -1));
}

int	ft_strnicmp(const char *restrict s1, const char *restrict s2,
			size_t n)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;
	size_t				index;

	index = 0;
	if (!str1 | !str2)
		return ((str2 == NULL) - (str1 == NULL));
	if (n == 0)
		return (0);
	while (str1[index] && str2[index] && index < n - 1)
	{
		if (cmp_ic(str1[index], str2[index]) != 0)
			return (cmp_ic(str1[index], str2[index]));
		index++;
	}
	return (cmp_ic(str1[index], str2[index]));
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
