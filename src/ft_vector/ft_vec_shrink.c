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
	const size_t	curr_size = ft_vec_inuse(vec);
	void			*data_empl;

	if (!vec)
		return (false);
	if (!vec->data || !curr_size || !vec->cappacity)
		return (false);
	if (vec->cappacity == vec->n_e)
		return (true);
	data_empl = ft_malloc(curr_size);
	if (!data_empl)
		return (false);
	ft_memcpy(data_empl, vec->data, curr_size);
	vec->cappacity = vec->n_e;
	ft_free(vec->data);
	vec->data = data_empl;
	return (true);
}

bool	ft_vec_shrink_min(t_vector *v, size_t n)
{
	size_t	target_size;
	void	*data_empl;

	if (!v)
		return (false);
	if (!n || v->cappacity == v->n_e)
		return (ft_vec_shrink(v));
	target_size = ft_vec_inuse(v);
	if (!v->data || !target_size || !v->cappacity)
		return (false);
	if (target_size < (v->s_e * n))
		target_size = v->s_e * n;
	data_empl = ft_calloc(target_size, 1);
	if (!data_empl)
		return (false);
	ft_memcpy(data_empl, v->data, ft_vec_inuse(v));
	ft_free(v->data);
	v->cappacity = target_size / v->s_e;
	v->data = data_empl;
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
