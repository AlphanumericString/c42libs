/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:19:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/25 22:19:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include <stdio.h>

void	*ft_getmax(const void *data, t_arrinfo infos, t_data_cmp cmp)
{
	size_t	i;
	size_t	max;

	if (!infos.nmemb || !infos.sz || !data)
		return (NULL);
	i = 0;
	max = 0;
	while (i < infos.nmemb)
	{
		if (cmp(data + i * infos.sz, data + max * infos.sz) > 0)
			max = i;
		i++;
	}
	return ((void *)data + max * infos.sz);
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
