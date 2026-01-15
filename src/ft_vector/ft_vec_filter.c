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
#include <stdio.h>

void	ft_vec_filter(t_vector *vec, t_data_is func, t_data_apply del)
{
	size_t	i;
	size_t	j;

	if (!vec || !vec->n_e || !vec->s_e)
		return ;
	i = 0;
	while (i < vec->n_e)
	{
		while (i < vec->n_e && func(ft_vec_at(vec, i)) == true)
			i++;
		j = 0;
		while ((i + j) < vec->n_e && func(ft_vec_at(vec, i + j)) == false)
			j++;
		if (j)
			ft_vec_nremove(vec, i, j, del);
	}
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
