/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:47:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:38:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "tests/tests__all_modules_tests.h"
#include <stdio.h>

int	test_vec_pop(void)
{
	t_vector	*vec;
	const char	*str;

	vec = ft_vec_new();
	ft_vec_add(&vec, "value1");
	ft_vec_add(&vec, "value2");
	ft_vec_add(&vec, "value3");
	str = ft_vec_pop(vec);
	if (!str || ft_strcmp(str, "value3") != 0 || vec->count != 2)
		return (1);
	str = ft_vec_pop(vec);
	if (!str || ft_strcmp(str, "value2") != 0 || vec->count != 1)
		return (2);
	str = ft_vec_pop(vec);
	if (!str || ft_strcmp(str, "value1") != 0 || vec->count != 0)
		return (3);
	str = ft_vec_pop(vec);
	if (str)
		return (4);
	return (ft_vec_destroy(&vec), 0);
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
