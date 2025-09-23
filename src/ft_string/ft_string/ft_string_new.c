/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:00:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:36:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_tstring.h"

t_string	*ft_string_new(size_t capacity)
{
	t_string	*new;

	new = ft_calloc(1, sizeof(t_string));
	if (!new)
		return (NULL);
	if (capacity < FT_TSTR_BUFF)
		capacity = FT_TSTR_BUFF;
	new->str = ft_calloc(capacity, sizeof(char));
	if (!new->str)
		return (ft_free(new), NULL);
	new->capacity = capacity;
	new->length = 0;
	return (new);
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
