/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsi_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:05:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/08/25 23:14:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_sis_tests.h"

int	tsi_ispath(void)
{
	const char	*valid_str[32] = {
		"/example/of/path", "./../toto/", "./././", "~/Doc", "~/../", "/root/",
		"/toto youhou/", "/\\/root", "./.../.../", "//", "///",
		"/root/\n*prout*\n/somefile", NULL};
	const char	*err_str[32] = {
		"/looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
		"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
		"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
		"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
		"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooong_filename",
		"",
		NULL};
	size_t		i;

	i = 0;
	while (valid_str[i])
		if (ft_str_ispath(valid_str[i++]) != true)
			return (i);
	i = 0;
	while (err_str[i])
		if (ft_str_ispath(err_str[i++]) != false)
			return (i + 32);
	if (ft_str_ispath(NULL) != false)
		return (65);
	return (EXIT_SUCCESS);
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

