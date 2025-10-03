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

#include "types/ft_vector_types.h"
#include "ft_vector.h"

void	*ft_vec_find(const t_vector *restrict vector,
			const void *restrict key, const t_data_cmp cmp)
{
	size_t	i;

	if (!vector->s_e || !vector->n_e || !vector->data)
		return (NULL);
	i = 0;
	while (i < vector->n_e)
	{
		if (key == ft_vec_at(vector, i) || (cmp
				&& cmp(ft_vec_at(vector, i), key) == 0))
			return (ft_vec_at(vector, i));
		i++;
	}
	return (NULL);
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
