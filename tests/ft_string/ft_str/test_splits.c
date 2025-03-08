/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_splits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:22:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:44:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

int	tests_splits(void)
{
	const char	*str;
	char		**res;
	size_t		i;

	str = "path/to/file:another/path:yet/another/path";
	res = ft_splits(str, " /:");
	if (ft_strcmp(res[0], "path") != 0 || ft_strcmp(res[1], "to") != 0 || \
	ft_strcmp(res[2], "file") != 0 || ft_strcmp(res[3], "another") != 0 || \
	ft_strcmp(res[4], "path") != 0 || ft_strcmp(res[5], "yet") != 0 || \
	ft_strcmp(res[6], "another") != 0 || ft_strcmp(res[7], "path") != 0 || \
	res[8])
		return (1);
	i = 0;
	while (res[i])
		ft_free(res[i++]);
	ft_free(res);
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
