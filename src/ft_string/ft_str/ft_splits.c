/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:48:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:34:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static size_t	loc_get_nbwords(const char *str, const char *delim)
{
	size_t	ret;
	size_t	i;
	size_t	inword;

	ret = 0;
	i = 0;
	inword = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strchr(delim, str[i++]))
		{
			if (inword == 1)
				ret++;
			inword = 0;
		}
		else
			inword = 1;
	}
	if (inword == 1)
		ret++;
	return (ret);
}

char	**ft_splits(const char *str, const char *delim)
{
	char	*str_cpy;
	char	*s;
	size_t	offset_words;
	char	**words;

	words = ft_calloc(sizeof(char *), (loc_get_nbwords(str, delim) + 1));
	if (!words)
		return (NULL);
	offset_words = 0;
	str_cpy = ft_strdup(str);
	s = ft_strtok(str_cpy, delim);
	while (s)
	{
		words[offset_words++] = ft_strdup(s);
		if (!words[offset_words - 1])
			return (ft_free_2d((void **)words), NULL);
		s = ft_strtok(NULL, delim);
	}
	ft_free(str_cpy);
	return (words);
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
