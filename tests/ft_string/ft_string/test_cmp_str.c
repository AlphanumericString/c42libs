/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmp_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_cmp_str(void)
{
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from("Hello");
	if (ft_string_cmpstr(str, str2) != 0)
		return (1);
	ft_string_destroy(&str2);
	str2 = ft_string_from("Hello World");
	if (ft_string_cmpstr(str, str2) >= 0)
		return (2);
	ft_string_destroy(&str2);
	str2 = ft_string_from("Hell");
	if (ft_string_cmpstr(str, str2) <= 0)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
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
