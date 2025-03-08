/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:55:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:35:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tot;
	size_t	off;
	char	*ret;

	tot = 0;
	if (s1)
		tot += ft_strlen(s1);
	if (s2)
		tot += ft_strlen(s2);
	ret = ft_calloc(sizeof(char), (tot + 1));
	if (!ret)
		return (NULL);
	off = 0;
	tot = 0;
	while (s1 && s1[off])
	{
		ret[off] = s1[off];
		off++;
	}
	while (s2 && s2[tot])
		ret[off++] = s2[tot++];
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
