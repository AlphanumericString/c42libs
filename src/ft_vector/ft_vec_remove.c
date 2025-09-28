/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:03:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_vector.h"

void	ft_vec_remove(t_vector *vector, size_t n, void (*del)(void *))
{
	if (n >= vector->nb_e)
		return ;
	if (del)
		del(vector->datas[n]);
	vector->datas[n] = NULL;
	ft_vec_shift(vector, n, 1);
}

void	ft_vec_remove_if(t_vector *vector, t_data_is func, t_data_apply del)
{
	size_t	i;

	i = 0;
	while (i < vector->nb_e)
	{
		if (func(vector->datas[i]))
			ft_vec_remove(vector, i, del);
		else
			i++;
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
