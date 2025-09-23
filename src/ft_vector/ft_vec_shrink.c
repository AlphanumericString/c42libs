/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_shrink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:23:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

bool	ft_vec_shrink(t_vector *vec)
{
	void	**new_datas;
	size_t	i;

	if (vec->count == vec->cappacity)
		return (true);
	new_datas = ft_calloc(sizeof(void *), vec->count);
	if (!new_datas)
		return (false);
	i = 0;
	while (i < vec->count)
	{
		new_datas[i] = vec->datas[i];
		i++;
	}
	ft_free(vec->datas);
	vec->datas = new_datas;
	vec->cappacity = vec->count;
	return (true);
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
