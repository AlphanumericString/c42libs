/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:17:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_set(t_string *str, const char *new_str)
{
	char	*s;
	int		r;

	if (!new_str)
		return (-1);
	s = ft_strdup(new_str);
	r = ft_string_set_inplace(str, s);
	if (r == 0)
		ft_free(s);
	return (r);
}

int	ft_string_set_n(t_string *str, const char *new_str, size_t n)
{
	size_t	new_len;

	if (!str || !new_str)
		return (-1);
	new_len = ft_strlen(new_str) + 1;
	if (new_len > n)
		new_len = n;
	if (new_len >= str->capacity)
	{
		if (ft_string_reserve(str, new_len + 1) == -1)
			return (0);
	}
	ft_memcpy(str->str, new_str, new_len);
	str->str[new_len] = '\0';
	str->length = new_len;
	return (1);
}

int	ft_string_set_inplace(t_string *str, char *new_str)
{
	size_t	new_len;

	if (!str || !new_str)
		return (0);
	new_len = ft_strlen(new_str);
	str->length = new_len;
	if (str->str)
		ft_free(str->str);
	str->str = new_str;
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
