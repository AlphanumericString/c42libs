/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambdas_general.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:08:37 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:12:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests_lambda_functions.h"

#include <stdbool.h>

void	**creat_tb(void)
{
	static int	a;
	static int	b;
	static int	c;
	static int	*tab[3] = { &a, &b, &c };

	a = 42;
	b = 43;
	c = 44;
	tab[0] = &a;
	tab[1] = &b;
	tab[2] = &c;
	return ((void **)tab);
}

bool	is42(const void *data)
{
	if (!data)
		return (false);
	return (*(int *)data == 42);
}

int	cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
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
