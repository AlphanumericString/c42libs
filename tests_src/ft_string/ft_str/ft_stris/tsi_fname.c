/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsi_fname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:05:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/08/24 17:05:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_stris.h"
#include "tests/str__str_sis_tests.h"

int	tsi_isfname(void)
{
	const char	*valid_str[20] = {
		"long file name", "a.c", "_", "\033[0m", NULL};
	const char	*err_str[20] = {
		"this/is/not/a/file", "", NULL};
	size_t		i;

	i = 0;
	while (valid_str[i])
		if (ft_str_isfname(valid_str[i++]) != true)
			return (i);
	i = 0;
	while (err_str[i])
		if (ft_str_isfname(err_str[i++]) != false)
			return (i + 20);
	if (ft_str_isfname(NULL) != false)
		return (40);
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
