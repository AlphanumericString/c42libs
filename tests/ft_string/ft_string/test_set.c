/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:50:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_string_set(void)
{
	t_string	*str;
	const char	*src;
	const char	*res;

	src = "Hello world this is zod!";
	str = ft_string_new(0);
	ft_string_set(str, src);
	res = ft_string_get(str);
	if (ft_strcmp(src, res) != 0)
		return (1);
	ft_string_destroy(&str);
	str = ft_string_new(99);
	ft_string_set(str, src);
	res = ft_string_get(str);
	if (ft_strcmp(src, res) != 0)
		return (2);
	ft_string_destroy(&str);
	return (0);
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
