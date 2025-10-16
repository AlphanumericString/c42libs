/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_atr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_char.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

static void	*loc_strtoupper(void *data)
{
	char	*str;
	int		i;

	if (!data)
		return (NULL);
	i = 0;
	str = data;
	while (str[i])
		if (ft_isalpha(str[i++]))
			str[i - 1] = ft_toupper(str[i - 1]);
	return ((void *)str);
}

int	tca_atr(void)
{
	char	**arr;

	arr = ft_split("Hello|World|42", '|');
	ft_atr((t_arr)arr, (t_data_tr_i) NULL);
	ft_atr((t_arr) NULL, (t_data_tr_i)loc_strtoupper);
	if (ft_strcmp(arr[0], "Hello") != 0
		|| ft_strcmp(arr[1], "World") != 0
		|| ft_strcmp(arr[2], "42") != 0)
		return (ft_afree((void **)arr), 1);
	ft_atr((t_arr)arr, (t_data_tr_i)loc_strtoupper);
	if (ft_strcmp(arr[0], "HELLO") != 0
		|| ft_strcmp(arr[1], "WORLD") != 0
		|| ft_strcmp(arr[2], "42") != 0)
		return (ft_afree((void **)arr), 1);
	return (ft_afree((void **)arr), 0);
}

int	tca_antr(void)
{
	char	**arr;

	arr = ft_split("Hello|World|42", '|');
	ft_antr((t_arr)arr, 0, NULL);
	ft_antr(NULL, 1, (t_data_tr_i)loc_strtoupper);
	ft_antr((t_arr)arr, 1, NULL);
	ft_antr((t_arr)arr, 0, loc_strtoupper);
	if (ft_strcmp(arr[0], "Hello") != 0 || ft_strcmp(arr[1], "World") != 0
		|| ft_strcmp(arr[2], "42") != 0)
		return (ft_afree((void **)arr), 1);
	ft_antr((t_arr)arr, 1, loc_strtoupper);
	if (ft_strcmp(arr[0], "HELLO") != 0 || ft_strcmp(arr[1], "World") != 0
		|| ft_strcmp(arr[2], "42") != 0)
		return (ft_afree((void **)arr), 2);
	ft_antr((t_arr)arr, 42, loc_strtoupper);
	if (ft_strcmp(arr[0], "HELLO") != 0 || ft_strcmp(arr[1], "WORLD") != 0
		|| ft_strcmp(arr[2], "42") != 0)
		return (ft_afree((void **)arr), 3);
	return (ft_afree((void **)arr), 0);
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
