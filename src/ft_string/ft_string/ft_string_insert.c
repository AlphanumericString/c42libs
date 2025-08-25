/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:22:33 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 22:37:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_insert(t_string *str, const char *insert, size_t index)
{
	size_t	insert_len;
	size_t	new_len;
	char	*new_str;

	if (!insert || !str)
		return (0);
	insert_len = ft_strlen(insert);
	if (index > str->length)
		index = str->length;
	new_len = str->length + insert_len;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert, insert_len);
	ft_memcpy(new_str + index + insert_len, str->str + index, str->length
		- index);
	ft_free_clear((void **)&str->str);
	str->str = new_str;
	if (index == str->length)
		str->str[new_len] = '\0';
	str->length = new_len;
	str->capacity += insert_len;
	return (1);
}

int	ft_string_insert_n(t_string *str, const char *insert, size_t index,
		size_t n)
{
	size_t	new_len;
	char	*new_str;

	if (index > str->length)
		index = str->length;
	new_len = str->length + n;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert, n);
	ft_memcpy(new_str + index + n, str->str + index, str->length - index);
	ft_free_clear((void **)&str->str);
	str->str = new_str;
	if (index == str->length)
		str->str[new_len] = '\0';
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}

int	ft_string_insert_c(t_string *str, char insert, size_t index)
{
	size_t	new_len;
	char	*new_str;

	if (index > str->length)
		index = str->length;
	new_len = str->length + 1;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str->str, index);
	new_str[index] = insert;
	ft_memcpy(new_str + index + 1, str->str + index, str->length - index);
	ft_free_clear((void **)&str->str);
	str->str = new_str;
	if (index == str->length)
		str->str[new_len] = '\0';
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}

int	ft_string_insert_s(t_string *restrict str,
		const t_string *restrict insert, size_t index)
{
	size_t	new_len;
	char	*new_str;

	if (index > str->length)
		index = str->length;
	new_len = str->length + insert->length;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert->str, insert->length);
	ft_memcpy(new_str + index + insert->length, str->str + index, str->length
		- index);
	ft_free_clear((void **)&str->str);
	str->str = new_str;
	if (index == str->length)
		str->str[new_len] = '\0';
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}

int	ft_string_insert_s_n(t_string *restrict str,
		const t_string *restrict insert, size_t index, size_t n)
{
	size_t	new_len;
	char	*new_str;

	if (index > str->length)
		index = str->length;
	new_len = str->length + n;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert->str, n);
	ft_memcpy(new_str + index + n, str->str + index, str->length - index);
	ft_free_clear((void **)&str->str);
	str->str = new_str;
	if (index == str->length)
		str->str[new_len] = '\0';
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
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
