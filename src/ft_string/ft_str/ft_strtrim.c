/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:03:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:35:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	loc_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static size_t	loc_strtrim_size(size_t *offset, char const *s1,
		char const *set)
{
	size_t	ret_size;

	ret_size = ft_strlen(s1);
	*offset = 0;
	while (ret_size > 0 && loc_strchr(set, s1[ret_size - 1]) != -1)
		ret_size--;
	while (ret_size && s1[*offset] && loc_strchr(set, s1[*offset]) != -1)
	{
		(*offset)++;
		ret_size--;
	}
	return (ret_size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	ret_size;
	size_t	offset;
	size_t	offset_ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	offset_ret = 0;
	ret_size = loc_strtrim_size(&offset, s1, set);
	if (ret_size == 0)
		return (ft_strdup(""));
	ret = ft_calloc(sizeof(char), (ret_size + 1));
	if (!ret)
		return (ret);
	while (s1[offset] && ret_size--)
		ret[offset_ret++] = s1[offset++];
	offset--;
	while (loc_strchr(set, s1[offset--]) != -1)
		ret[offset_ret--] = 0;
	return (ret);
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
