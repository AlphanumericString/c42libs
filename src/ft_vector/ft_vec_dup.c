/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 05:58:13 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 05:58:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

t_vector *ft_vec_dup(const t_vector *o)
{
	t_vector *ret;
	void		*data_;

	if (!o || !o->data || !o->s_e)
		return (NULL);
	data_ = ft_calloc(o->n_e, o->s_e);
	if (!data_)
		return (NULL);
	ft_memcpy(data_, o->data, ft_vec_inuse(o));
	ret = ft_calloc(sizeof(t_vector), 1);
	if (!ret)
		return (ft_free(data_), NULL);
	*ret = *o;
	ret->data = data_;
	return (ret);
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
