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
#include "ft_mem.h"
#include "ft_vector.h"
#include <stddef.h>
#include <stdio.h>

void	ft_vec_remove(t_vector *vec, size_t idx, t_data_apply del)
{
	if (!vec || !vec->n_e || !vec->s_e || idx >= vec->n_e)
		return ;
	if (del)
		del(ft_vec_at(vec, idx));
	if (idx + 1 >= vec->n_e)
		return (vec->n_e--, (void)0);
	ft_memcpy(ft_vec_at(vec, idx), ft_vec_at(vec, idx + 1),
		vec->s_e * (vec->n_e - idx - 1));
	vec->n_e--;
	return ;
}

void	ft_vec_filterout(t_vector *vec, t_data_is func, t_data_apply del)
{
	size_t	i;
	size_t	j;

	if (!vec || vec->n_e == 0 || vec->s_e == 0)
		return ;
	i = 0;
	while (i < vec->n_e)
	{
		while (i < vec->n_e && func(ft_vec_at(vec, i)) == false)
			i++;
		j = 0;
		while ((i + j) < vec->n_e && func(ft_vec_at(vec, i + j)) == true)
			j++;
		if (j)
			ft_vec_nremove(vec, i, j, del);
	}
}

// NOTE: maybe move the ft_bzero calls to another ft_vec_* function to allow
//	for : 1. better performance, 2. might be usefull in some other cases to
//	keep the array clean
void	ft_vec_nremove(t_vector *vec, size_t start, size_t nb_todel,
			t_data_apply del)
{
	size_t	i;

	i = 0;
	if (!vec || !vec->n_e || !vec->s_e || start > vec->n_e || !nb_todel)
		return ;
	if ((start + nb_todel) >= vec->n_e)
	{
		while (++i < nb_todel + 1 && del)
			del(ft_vec_at(vec, i - 1));
		ft_bzero(ft_vec_at(vec, start), (vec->n_e - start) * vec->s_e);
		vec->n_e = start;
		return ;
	}
	while (++i < (nb_todel + 1) && del)
		del(ft_vec_at(vec, i - 1));
	i = 0;
	i = vec->n_e - (start + nb_todel);
	ft_memcpy(ft_vec_at(vec, start), ft_vec_at(vec, start + nb_todel),
		i * vec->s_e);
	vec->n_e -= nb_todel;
	ft_bzero(vec->data + (vec->n_e * vec->s_e),
		vec->cappacity - ft_vec_inuse(vec));
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
