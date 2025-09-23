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

#include "ft_mem.h"
#include "ft_string.h"

static int	loc_strchr(const char *str, int c)
{
	const char	*s = ft_strchr(str, c);

	if (!s)
		return (-1);
	return (s - str);
}

static size_t	loc_strtrim_size(size_t *offset, char const *s1,
		char const *set)
{
	size_t	ret_size;

	ret_size = ft_strlen(s1);
	*offset = 0;
	while (ret_size > 0 && loc_strchr(set, s1[ret_size - 1]) != -1)
		ret_size--;
	while (ret_size-- && loc_strchr(set, s1[(*offset)++]) != -1)
		;
	return ((*offset)--, ret_size + 1);
}

// current impl allocates only needed memory
// maybe a ft_strtrim_inplace(ft_strdup(s1), set);
// would be "simpler", but we "shrink" the string to only what is needed
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
	while (s1[offset] && ret_size-- && ret)
		ret[offset_ret++] = s1[offset++];
	return (ret);
}

// +2 -> null + position of back_offset
char	*ft_strtrim_inplace(char *s1, const char *set)
{
	char	*front_offset;
	char	*back_offset;

	if (!s1 || !set || !*set)
		return (s1);
	front_offset = s1;
	back_offset = s1 + ft_strlen(s1);
	while (*front_offset && loc_strchr(set, *front_offset) != -1)
		front_offset++;
	while (back_offset > front_offset && ft_strchr(set, *back_offset) != NULL)
		back_offset--;
	if (front_offset == back_offset && ft_strchr(set, *front_offset) != NULL)
		return (*s1 = '\0', s1);
	*(back_offset + 1) = '\0';
	ft_memmove(s1, front_offset, back_offset - front_offset + 2);
	return (s1);
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
