/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:40:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

bool	ft_vec_cat(t_vector *vec_a, const t_vector *vec_b)
{
	bool	ret;

	ret = true;
	if (vec_a->s_e != vec_b->s_e)
		return (false);
	if (vec_a->cappacity < (ft_vec_inuse(vec_a) + ft_vec_inuse(vec_b)))
		ret = ft_vec_reserve(vec_a, vec_a->cappacity + ft_vec_inuse(vec_b));
	if (!ret)
		return (false);
	ft_memcpy(vec_a->data + ft_vec_inuse(vec_a), vec_b->data,
		ft_vec_inuse(vec_b));
	vec_a->n_e += vec_b->n_e;
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
