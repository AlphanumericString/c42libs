/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:36:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tstring.h"

int	ft_string_cmp(const t_string *str, const char *cmp)
{
	return (ft_strcmp(str->str, cmp));
}

int	ft_string_ncmp(const t_string *str, const char *cmp, size_t n)
{
	return (ft_strncmp(str->str, cmp, n));
}

int	ft_string_cmpstr(const t_string *str, const t_string *cmp)
{
	if (str->length != cmp->length)
		return (str->length - cmp->length);
	return (ft_strcmp(str->str, cmp->str));
}

int	ft_string_ncmpstr(const t_string *str, const t_string *cmp, size_t n)
{
	if (n < str->length && n < cmp->length)
		return (ft_strncmp(str->str, cmp->str, n));
	if (str->length != cmp->length)
		return (str->length - cmp->length);
	return (ft_strcmp(str->str, cmp->str));
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
