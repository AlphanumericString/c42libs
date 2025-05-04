/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:24:43 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:04:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_append(t_string *str, const char *append)
{
	size_t	len;

	len = ft_strlen(append) + 1;
	if (str->length + len >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + len) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append, len);
	str->length += len - 1;
	return (0);
}

int	ft_string_append_n(t_string *str, const char *append, size_t n)
{
	if (str->length + n + 1 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + n + 1) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append, n);
	str->length += n;
	str->str[str->length] = '\0';
	return (0);
}

int	ft_string_append_c(t_string *str, char c)
{
	if (str->length + 2 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + 2) == -1)
			return (-1);
	}
	str->str[str->length] = c;
	str->str[str->length + 1] = '\0';
	str->length += 1;
	return (0);
}

int	ft_string_append_s(t_string *restrict str, const t_string *restrict append)
{
	if (str->length + append->length + 1 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + append->length + 1) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append->str, append->length + 1);
	str->length += append->length;
	str->str[str->length] = '\0';
	return (0);
}

int	ft_string_append_s_n(t_string *restrict str, \
	const t_string *restrict append, size_t n)
{
	if (str->length + n + 1 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + n + 1) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append->str, n);
	str->length += n;
	str->str[str->length] = '\0';
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
