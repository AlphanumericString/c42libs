/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:35:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:34:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static bool	setup(char **res, const char *targ, size_t targ_len, size_t sub_len)
{
	char	*occurence;
	size_t	nb_occurence;

	occurence = ft_strnstr(*res, targ, ft_strlen(*res));
	nb_occurence = 0;
	while (occurence)
	{
		occurence = ft_strnstr(occurence + 1, targ, ft_strlen(occurence + 1));
		nb_occurence++;
	}
	*res = ft_malloc(ft_strlen(*res) + (sub_len - targ_len) * nb_occurence + 1);
	if (!*res)
		return (false);
	return (true);
}

char	*ft_str_replace(const char *str, const char *target, \
					const char *substitute)
{
	char			*res;
	char			*ret;
	char			*occurence;
	const size_t	target_len = ft_strlen(target);
	const size_t	substitute_len = ft_strlen(substitute);

	occurence = ft_strnstr(str, target, ft_strlen(str));
	if (!occurence)
		return (ft_strdup(str));
	res = (char *)str;
	if (!setup(&res, target, target_len, substitute_len))
		return (NULL);
	ret = res;
	while (occurence)
	{
		ft_memcpy(res, str, occurence - str);
		res += occurence - str;
		ft_memcpy(res, substitute, substitute_len);
		res += substitute_len;
		str = occurence + target_len;
		occurence = ft_strnstr(str, target, ft_strlen(str));
	}
	return (ft_strlcpy(res, str, ft_strlen(str) + 1), ret);
}

char	*ft_str_replace_chr(char *str, char to_replace, char replace_by)
{
	char		*ptr;

	ptr = str;
	str = ft_strchr(str, to_replace);
	while (str && *str)
	{
		*str = replace_by;
		str++;
		str = ft_strchr(str, to_replace);
	}
	return (ptr);
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
