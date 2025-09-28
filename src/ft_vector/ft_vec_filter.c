/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_vector.h"

void	ft_vec_filter(t_vector *vec, t_data_is func, t_data_apply del)
{
	size_t	i;
	size_t	shift_count;

	i = 0;
	while (vec->nb_e > i)
	{
		shift_count = 0;
		while (vec->nb_e > i && func(vec->datas[i]) == false)
		{
			if (del)
				del(vec->datas[i]);
			shift_count++;
			vec->datas[i++] = NULL;
		}
		ft_vec_shift(vec, i - shift_count, shift_count);
		i -= shift_count;
		while (vec->nb_e > i && func(vec->datas[i]) == true)
			i++;
	}
	return ;
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
