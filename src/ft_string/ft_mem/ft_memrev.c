/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:31:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/22 14:31:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>

// e_n -> elements number
// e_s -> elements size
void	*ft_memnrev(void *data, size_t e_n, size_t e_s)
{
	size_t	i;

	if (e_n < 2 || !e_s)
		return (data);
	i = 0;
	e_n--;
	while (i < e_n)
	{
		ft_swap((char *)data + (i * e_s), (char *)data + (e_n * e_s), e_s);
		i++;
		e_n--;
	}
	return (data);
}

// n -> nb bytes to rev
void	*ft_memrev(void *data, size_t n)
{
	return (ft_memnrev(data, n, sizeof(char)));
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
