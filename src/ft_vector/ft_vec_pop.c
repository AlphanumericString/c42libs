/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:00:25 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_vector_types.h"
#include "ft_vector.h"

void	*ft_vec_pop(t_vector *vec)
{
	void	*ret;

	if (!vec->n_e || !vec->s_e)
		return (NULL);
	ret = ft_vec_at(vec, vec->n_e - 1);
	vec->n_e--;
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
