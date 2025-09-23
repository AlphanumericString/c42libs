/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:42:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 22:37:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tstring.h"
#include "ft_mem.h"

t_string	*ft_string_substr(const t_string *restrict str, size_t start,
		size_t len)
{
	t_string	*new;

	if (!str || start > str->length)
		return (NULL);
	if (len > str->length - start)
		len = str->length - start;
	new = ft_string_new(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new->str, str->str + start, len);
	new->length = len;
	new->str[new->length] = '\0';
	return (new);
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
