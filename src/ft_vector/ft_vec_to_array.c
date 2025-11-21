/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 17:01:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "types/ft_vector_types.h"
#include "ft_vector.h"

void	*ft_vec_to_array(t_vector **vec)
{
	void	*array;

	array = NULL;
	if (*vec)
		array = (*vec)->data;
	if (*vec)
		ft_free_clear((void **)vec);
	return (array);
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
