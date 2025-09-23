/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:56:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/12 23:27:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

// ((str2==NULL)-(str1==NULL))	=> !str2 && !str1 => (1-1) -> eq
//								=> !str2 &&  str1 => (1-0) -> str1 > str2
//								=>  str2 && !str1 => (0-1) -> str1 < str2

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;
	size_t				index;

	index = 0;
	if (!str1 | !str2)
		return ((str2 == NULL) - (str1 == NULL));
	if (n == 0)
		return (0);
	while (str1[index] == str2[index] && str1[index] && index < n - 1)
		index++;
	return (str1[index] - str2[index]);
}

int	ft_strnrcmp(const char *restrict s1, const char *restrict s2,
		size_t n)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;
	size_t				len1;
	size_t				len2;

	if (!str1 | !str2)
		return ((str2 == NULL) - (str1 == NULL));
	if (n == 0)
		return (0);
	len1 = ft_strlen((const char *)str1);
	len2 = ft_strlen((const char *)str2);
	while (len1 && len2 && str1[len1 - 1] == str2[len2 - 1] && n--)
	{
		len1--;
		len2--;
	}
	if (n == 0 && str1[len1 - 1] == str2[len2 - 1])
		return (0);
	if (len1 == 0 || len2 == 0)
		return ((len2 == 0) - (len1 == 0));
	return (str1[len1 - 1] - str2[len2 - 1]);
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
