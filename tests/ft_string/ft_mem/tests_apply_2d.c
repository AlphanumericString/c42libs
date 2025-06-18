/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_apply_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:05:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:35:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

static void	to_a(void *ptr)
{
	char	*sptr;

	sptr = (char *)ptr;
	while (*sptr)
	{
		*sptr = 'a';
		sptr++;
	}
}

int	test_apply_2d(void)
{
	char	*arr2d[4];
	size_t	i;

	i = 0;
	while (i < 3)
		arr2d[i++] = ft_strdup("Hello World");
	arr2d[i] = NULL;
	ft_aapply((void **)arr2d, to_a);
	if (ft_strcmp(arr2d[0], "aaaaaaaaaaa") != 0 || ft_strcmp(arr2d[1],
			"aaaaaaaaaaa") != 0 || ft_strcmp(arr2d[2], "aaaaaaaaaaa") != 0)
		return (1);
	return (ft_aapply((void **)arr2d, ft_free), 0);
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
