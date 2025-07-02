/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:51:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 16:02:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

// todo: maybe pos? return maybe int/void * with either the i/-1 where match
//		or a valid adress of the array/null.
const void	*ft_afind(t_const_arr arr, const void *cmp_d)
{
	size_t	i;

	i = 0;
	if (!arr || !arr[0] || !cmp_d)
		return (NULL);
	while (arr[i])
	{
		if (arr[i] == cmp_d)
			return (arr[i]);
		i++;
	}
	return (NULL);
}

const void	*ft_afind_with(t_const_arr arr, const void *cmp_d,
				t_data_cmp cmp)
{
	size_t	i;

	i = 0;
	if (!cmp || !arr || !arr[0] || !cmp_d)
		return (NULL);
	while (arr[i])
	{
		if (cmp(arr[i], cmp_d) == 0)
			return (arr[i]);
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
