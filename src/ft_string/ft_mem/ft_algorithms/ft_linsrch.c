/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:36:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 14:16:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"
#include <stddef.h>
#include <stdio.h>

size_t ft_linsrch_pos(const void *data, const t_arrinfo infos, const void *elem,
					t_data_cmp cmp)
{
	size_t i;

	if (!data || !infos.sz || !infos.nmemb || !cmp)
		return (0);
	i = 0;
	while (cmp((char *)data + i, elem) > 0)
		i++;
	return (i);
}

void	*ft_linsrch(const void *data, const t_arrinfo infos, const void *elem,
					t_data_cmp cmp)
{
	size_t i;

	i = 0;
	if (!data || !infos.sz || !infos.nmemb || !cmp)
		return (NULL);
	while (i < infos.nmemb)
	{
		if (!cmp((char *)data + i, elem))
			return ((void *)((char *)data + i));
		i++;
	}
	return (NULL);
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
