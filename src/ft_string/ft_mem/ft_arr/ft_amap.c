/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_amap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:45:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/03 01:45:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include <stddef.h>

t_arr	ft_amap(t_const_arr array, t_data_tr f)
{
	size_t	i;
	t_arr	result;

	if (!array || !f)
		return (NULL);
	result = ft_malloc(sizeof(*result) * (ft_alen(array) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (array[i])
	{
		result[i] = f(array[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

t_arr	ft_anmap(t_const_arr array, size_t n, t_data_tr f)
{
	size_t	i;
	t_arr	result;

	if (!array || !f)
		return (NULL);
	if (n > ft_alen(array))
		n = ft_alen(array);
	else if (n == 0)
		return (ft_calloc(1, sizeof(*result)));
	result = ft_malloc(sizeof(*result) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (array[i] && i < n)
	{
		result[i] = f(array[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
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
