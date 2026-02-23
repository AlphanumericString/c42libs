/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:01:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include <stdlib.h>

bool	ft_vec_reserve(t_vector *vec, size_t size)
{
	void	*data_empl;
	size_t	new_cap;

	if (!vec || !size)
		return (false);
	if (vec->cappacity > size)
		return (true);
	new_cap = FT_VECTOR_BASE_LEN;
	while (new_cap < (size + vec->cappacity))
		new_cap *= 2;
	size = new_cap * vec->s_e;
	data_empl = ft_malloc(size);
	if (!data_empl)
		return (false);
	ft_memcpy(data_empl, vec->data, ft_vec_inuse(vec));
	vec->cappacity = new_cap;
	if (vec->data)
		ft_free(vec->data);
	vec->data = data_empl;
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
