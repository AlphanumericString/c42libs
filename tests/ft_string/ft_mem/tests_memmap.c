/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:39 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/14 23:44:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"

int	test_memmap(void)
{
	const char	*tb[3] = {"Hello", "World", "!"};
	char		**str2;

	str2 = (char **) ft_memmap((void *)tb, sizeof(tb) / sizeof(tb[0]),
			(t_data_tr)ft_strdup);
	if (ft_strcmp(str2[0], "Hello") || ft_strcmp(str2[1], "World") || \
	ft_strcmp(str2[2], "!"))
		return (1);
	ft_free(str2[0]);
	ft_free(str2[1]);
	ft_free(str2[2]);
	ft_free(str2);
	if (ft_memmap(NULL, 0, (t_data_tr)ft_strdup) != NULL || \
	ft_memmap((void *)tb, 0, (t_data_tr)ft_strdup) != NULL || \
	ft_memmap((void *)tb, sizeof(tb) / sizeof(tb[0]), NULL))
		return (2);
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
