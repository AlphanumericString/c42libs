/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:46:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *str, int c)
{
	return (ft_strnrchr(str, -1, c));
}

char	*ft_strnrchr(const char *str, size_t n, int c)
{
	const char	target = (char)c;
	size_t		len;
	char		*ret;
	size_t		i;

	if (!str | !n)
		return (NULL);
	len = ft_strnlen(str, n);
	ret = NULL;
	i = 0;
	while (i < len)
	{
		if (str[i] == target)
			ret = (char *)str + i;
		i++;
	}
	if (i < n && str[i] == target)
		ret = (char *)str + i;
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
