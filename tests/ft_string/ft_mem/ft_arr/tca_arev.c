/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_arev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:28:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/03 11:28:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"
#include "tests/tests.h"
#include <string.h>

int	tca_arev(void)
{
	const char	*arr[] = {"a", "b", "c", "d", NULL};
	const char	*arr1[] = {"a", "b", "c", "d", "e", NULL};
	const char	*arr2[] = {"a", NULL};

	ft_arev((t_iconst_arr)arr);
	if (ft_strcmp(arr[0], "d") || ft_strcmp(arr[1], "c")
		|| ft_strcmp(arr[2], "b") || ft_strcmp(arr[3], "a")
		|| arr[4] != NULL)
		return (1);
	ft_arev((t_iconst_arr)arr1);
	if (ft_strcmp(arr1[0], "e") || ft_strcmp(arr1[1], "d")
		|| ft_strcmp(arr1[2], "c") || ft_strcmp(arr1[3], "b")
		|| ft_strcmp(arr1[4], "a") || arr1[5] != NULL)
		return (2);
	ft_arev((t_iconst_arr)arr2);
	if (arr2[1] != NULL || ft_strcmp(arr2[0], "a"))
		return (3);
	ft_arev((t_iconst_arr)(const char *[1]){NULL});
	ft_arev(NULL);
	return (0);
}

int	tca_anrev(void)
{
	const char	*arr[] = {"a", "b", "c", "d", NULL};

	ft_anrev((t_iconst_arr)arr, 4);
	if (ft_strcmp(arr[0], "d") || ft_strcmp(arr[1], "c")
		|| ft_strcmp(arr[2], "b") || ft_strcmp(arr[3], "a")
		|| arr[4] != NULL)
		return (1);
	ft_anrev((t_iconst_arr)arr, 2);
	if (ft_strcmp(arr[0], "c") || ft_strcmp(arr[1], "d")
		|| ft_strcmp(arr[2], "b") || ft_strcmp(arr[3], "a")
		|| arr[4] != NULL)
		return (2);
	ft_anrev((t_iconst_arr)arr, 1);
	if (ft_strcmp(arr[0], "c") || ft_strcmp(arr[1], "d")
		|| ft_strcmp(arr[2], "b") || ft_strcmp(arr[3], "a")
		|| arr[4] != NULL)
		return (3);
	ft_anrev(NULL, 42);
	ft_anrev((t_iconst_arr)(const char *[1]){NULL}, 42);
	ft_anrev((t_iconst_arr)(const char *[2]){"toto", NULL}, 42);
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
