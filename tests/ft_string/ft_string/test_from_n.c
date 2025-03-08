/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_from_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_from_n(void)
{
	t_string	*str;

	str = ft_string_from_n("Hello World", 5);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5 || str->capacity < 5)
		return (2);
	ft_string_destroy(&str);
	str = ft_string_from_n(NULL, 5);
	if (str->length != 0 || str->capacity < 1)
		return (3);
	ft_string_destroy(&str);
	str = ft_string_from_n("Hello World", 0);
	if (str->length != 0 || str->capacity < 1)
		return (4);
	return (ft_string_destroy(&str), 0);
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
