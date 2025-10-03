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

#include "ft_math.h"
#include "ft_mem.h"
#include "ft_vector.h"

// 'new_size >= vec->cappacity' is over the top but if vec is by any means
// badly created this will save some asses
// new_size = max(curr_size, vec->se);
// unfortunately max cant be defined as a macro by norm....
bool	ft_vec_shrink(t_vector *vec)
{
	const size_t	curr_size = ft_vec_inuse(vec);
	size_t			new_size;
	void			*data_empl;

	if (!vec->s_e || curr_size >= vec->cappacity || !vec->data)
		return (false);
	new_size = curr_size;
	if (new_size < vec->s_e)
		new_size = vec->s_e;
	data_empl = ft_malloc(new_size);
	if (!data_empl)
		return (false);
	ft_memcpy(data_empl, vec->data, new_size);
	vec->cappacity = new_size;
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
