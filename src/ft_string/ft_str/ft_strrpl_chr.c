/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rpl_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:04:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/10 00:04:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_strrpl_chr(char *str, char srch, char rpl_c)
{
	return (ft_strnrpl_chr(str, -1, srch, rpl_c));
}

char	*ft_strrpl_chrs(char *str, const char *to_rpl, const char *rpl_by)
{
	return (ft_strnrpl_chrs(str, -1, to_rpl, rpl_by));
}

char	*ft_strnrpl_chr(char *str, size_t n, char srch, char rpl_c)
{
	char	*ptr;

	if (!n | !str)
		return (str);
	ptr = str;
	str = ft_strchr(str, srch);
	while (str && n > ((size_t)str - (size_t)ptr))
	{
		*str = rpl_c;
		str++;
		str = ft_strnchr(str, n - (str - ptr), srch);
	}
	return (ptr);
}

char	*ft_strnrpl_chrs(char *str, size_t n, const char *srch,
			const char *rpl_by)
{
	const char	*s = str;
	size_t		i;
	size_t		rpl_len;
	char		rpl;

	i = 0;
	if (!n | !str | !srch | !rpl_by || !*srch)
		return ((char *)s);
	rpl_len = ft_strlen(rpl_by);
	while (srch[i])
	{
		rpl = '\0';
		if (rpl_len)
			rpl = rpl_by[i % rpl_len];
		str = ft_strnrpl_chr(str, n, srch[i], rpl);
		while (!rpl && n && !*str)
		{
			str++;
			n--;
		}
		i++;
	}
	return ((char *)s);
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
