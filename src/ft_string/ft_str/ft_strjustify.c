/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjustify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:21:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/08/26 12:21:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_char.h"
#include "ft_string.h"

#include <stddef.h>
#include <stdio.h>

char	*ft_strwlgn_inplace(char *str, size_t width)
{
	const size_t	width_orig = width;
	size_t			i;
	size_t			p;

	str = ft_strtrim_inplace(str, "\f\n\r\t\v ");
	if (!ft_strrmdup_spaceall(str) || !*str)
		return (str);
	i = 0;
	while (str[i])
	{
		if (i > width)
		{
			str[p] = '\n';
			width = p + width_orig;
		}
		if (ft_isspace(str[i++]))
			p = i - 1;
	}
	return (ft_strcapitalize_grammar(str), str);
}

// static size_t	wordgrab(const char *str, const char **start,
//		const char **end)
// {
// 	if (!str || !*str)
// 		return (*start = 0, *end = 0, 0);
// 	while (*str && ft_isspace(*str))
// 		str++;
// 	*start = str;
// 	while (*str && !ft_isspace(*str))
// 		str++;
// 	*end = str;
// 	return ((size_t) * end - (size_t) * start);
// }
//
// static void	extract_len(size_t *t_len_out, const char *str, size_t width)
// {
// 	const char	*w_s;
// 	const char	*w_e;
// 	size_t		t_len;
// 	size_t		l_len;
//
// 	l_len = 0;
// 	t_len = 0;
// 	w_e = str;
// 	while (w_e)
// 	{
// 		wordgrab(w_e, &w_s, &w_e);
// 		if ((l_len + (w_e - w_s) + 1) > width)
// 		{
// 			t_len += width + 1;
// 			l_len = (w_e - w_s);
// 		}
// 		else
// 			l_len += ((w_e - w_s) + 1);
// 	}
// 	t_len += l_len;
// 	*t_len_out = t_len;
// }

// idea for space placement:
// replace the current ' '+'\n' pusher ->
// function takes the number of missing chars to reach width
// goes back to the previous '\n' count the number of 'holes'
// divide missing / holes ->
//		insert that many spaces in each hole
//		if there is a remainder add one more space in each hole from the left
//		  until the remainder is 0
// char	*ft_strjustify(const char *str, size_t width)
// {
// 	const char	*w_s;
// 	const char	*w_e;
// 	size_t		t_len;
// 	size_t		l_len;
// 	char		*ret;
//
// 	extract_len(&t_len, str, width);
// 	ret = ft_calloc(sizeof(char), t_len + 1);
// 	t_len = 0;
// 	w_e = str;
// 	l_len = 0;
// 	while (*w_e)
// 	{
// 		wordgrab(w_e, &w_s, &w_e);
// 		if ((l_len + (w_e - w_s) + 1) > width)
// 		{
// 			// push line break and spaces for 'missing' chars
// 			// reset line counter to word len
// 			while ((t_len + 1) % width)
// 				ret[t_len++] = ' ';
// 			ret[t_len++] = '\n';
// 			l_len = (w_e - w_s);
// 		}
// 		else
// 		{
// 			// push space + word len on line counter
// 			if (t_len != 0)
// 				ret[t_len++] = ' ';
// 			l_len += ((w_e - w_s) + 1);
// 		}
// 		// push word
// 		ft_memcpy(ret + t_len, w_s, (w_e - w_s));
// 		t_len += (w_e - w_s);
// 	}
// 	return (ft_strcapitalize_grammar(ret));
// }

char	*ft_strwlgn_nospace(const char *str, size_t width)
{
	char	*str_cpy;

	if (!str)
		return (NULL);
	str_cpy = ft_strdup(str);
	if (str_cpy)
		ft_strwlgn_inplace(str_cpy, width);
	return (str_cpy);
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
