/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:08:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/28 22:32:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "types/ft_vector_types.h"

// TODO: ft_vec_apply(ft_vec_dup(vec), func)
// missing: ft_vec_dup
t_vector	*ft_vec_map(const t_vector *restrict vec, const t_data_apply func)
{
	t_vector	*ret;
	void		*data_;
	size_t		i;

	i = 0;
	if (vec->n_e == 0 || vec->s_e == 0 || vec->data == NULL)
		return (NULL);
	data_ = ft_calloc(vec->n_e, vec->s_e);
	if (!data_)
		return (NULL);
	ft_memcpy(data_, vec->data, ft_vec_inuse(vec));
	while (i < vec->n_e)
		func(data_ + (i++ *vec->s_e));
	ret = ft_vec_convert_alloccarray(data_, vec->n_e, vec->s_e);
	if (!ret)
		return (ft_free(data_), NULL);
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
