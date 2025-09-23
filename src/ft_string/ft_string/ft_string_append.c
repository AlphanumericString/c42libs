/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:24:43 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 22:37:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tstring.h"
#include "ft_mem.h"

bool	ft_string_append(t_string *str, const char *append)
{
	size_t	len;

	if (!str || !append)
		return (false);
	len = ft_strlen(append);
	if (str->length + len >= str->capacity
		&& ft_string_resize(str, str->capacity + len) == false)
		return (false);
	ft_memcpy(str->str + str->length, append, len);
	str->length += len;
	return (true);
}

bool	ft_string_append_n(t_string *str, const char *append, size_t n)
{
	if (!str || !append)
		return (false);
	if (str->length + n >= str->capacity
		&& ft_string_resize(str, str->capacity + n) == false)
		return (false);
	ft_memcpy(str->str + str->length, append, n);
	str->length += n;
	str->str[str->length] = '\0';
	return (true);
}

bool	ft_string_append_c(t_string *str, char c)
{
	if (!str)
		return (false);
	if (str->length + 1 >= str->capacity
		&& ft_string_resize(str, str->capacity + 1) == false)
		return (false);
	str->str[str->length] = c;
	str->str[++str->length] = '\0';
	return (true);
}

bool	ft_string_append_s(t_string *restrict str,
			const t_string *restrict append)
{
	if (!str || !append)
		return (false);
	if (str->length + append->length + 1 >= str->capacity
		&& ft_string_resize(str, str->capacity + append->length) == false)
		return (false);
	ft_memcpy(str->str + str->length, append->str, append->length + 1);
	str->length += append->length;
	str->str[str->length] = '\0';
	return (true);
}

bool	ft_string_append_s_n(t_string *restrict str,
			const t_string *restrict append, size_t n)
{
	if (!str || !append)
		return (false);
	if (str->length + n >= str->capacity
		&& ft_string_resize(str, str->capacity + n) == false)
		return (false);
	ft_memcpy(str->str + str->length, append->str, n);
	str->length += n;
	str->str[str->length] = '\0';
	return (true);
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
