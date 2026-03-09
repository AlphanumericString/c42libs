/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:24:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:45:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

// PERF: 
// (char *)key)[0] == ((char *)elem)[0]
// performance trick, we check only the first char to check if we need the call
void	*ft_vec_find(const t_vector *restrict vec,
			const void *restrict key, const t_data_cmp cmp)
{
	size_t	i;
	void	*elem;

	if (!vec || !vec->s_e || !vec->n_e || !vec->data)
		return (NULL);
	i = 0;
	while (i < vec->n_e)
	{
		elem = ft_vec_at(vec, i++);
		if ((key == elem) || (cmp && cmp(elem, key) == 0))
			return (elem);
		else if (((char *)key)[0] == ((char *)elem)[0]
			&& ft_memcmp(elem, key, vec->s_e))
			return (elem);
	}
	return (NULL);
}

void	*ft_vec_findget(const t_vector *vector, const void *key,
				t_data_cmp cmp, void *ret)
{
	void	*e;

	if (!vector || !ret)
		return (NULL);
	ft_bzero(ret, vector->s_e);
	e = ft_vec_find(vector, key, cmp);
	if (!e)
		return (NULL);
	ft_memcpy(ret, e, vector->s_e);
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
