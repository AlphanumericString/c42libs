/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:51:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:36:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_string_chr(const t_string *str, char c)
{
	size_t	i;

	i = 0;
	while (i < str->length)
	{
		if (str->str[i] == c)
			return (str->str + i);
		i++;
	}
	if (c == '\0')
		return (str->str + i);
	return (NULL);
}

char	*ft_string_rchr(const t_string *str, char c)
{
	size_t	i;

	i = str->length;
	while (i > 0)
	{
		if (str->str[i] == c)
			return (str->str + i);
		i--;
	}
	if (str->str[i] == c)
		return (str->str + i);
	return (NULL);
}

ssize_t	ft_string_offset(const t_string *str, char c)
{
	char	*ptr;

	ptr = ft_string_chr(str, c);
	if (ptr)
		return (ptr - str->str);
	return (-1);
}

ssize_t	ft_string_roffset(const t_string *str, char c)
{
	char	*ptr;

	ptr = ft_string_rchr(str, c);
	if (ptr)
		return (ptr - str->str);
	return (-1);
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
