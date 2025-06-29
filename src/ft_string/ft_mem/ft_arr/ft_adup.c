/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:54:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 16:06:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"

#include "ft_arr.h"
#include "ft_string.h"

t_iconst_arr	ft_adup(t_const_arr arr)
{
	t_iconst_arr	ret;
	size_t			i;

	ret = NULL;
	if (!arr)
		return (ret);
	ret = ft_calloc(sizeof(const void *), ft_alen(arr) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		ret[i] = arr[i];
		i++;
	}
	ret[i] = NULL;
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
