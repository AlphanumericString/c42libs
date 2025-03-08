/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:14:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/14 23:34:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

void	**ft_memmap(void **src, size_t nb_e, t_data_tr f)
{
	void	**dst;
	size_t	i;

	if (!src || !f || !nb_e)
		return (NULL);
	dst = ft_malloc(nb_e * sizeof(void *));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < nb_e)
	{
		dst[i] = f(src[i]);
		i++;
	}
	return (dst);
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
