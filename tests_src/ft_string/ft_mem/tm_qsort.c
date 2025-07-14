/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:20:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests_lambda_functions.h"
#include "tests/str__mem_tests.h"

#define SET_SIZE 10
#define NB_TESTS 100

static int	tm_set(void)
{
	int	ar_out[SET_SIZE];
	int	i;

	i = 0;
	while (i < SET_SIZE)
		ar_out[i++] = rand() % 1000;
	ft_qsort(ar_out, SET_SIZE, sizeof(int), cmp_int);
	i = 0;
	while (i < SET_SIZE - 1)
	{
		if (ar_out[i] > ar_out[i + 1])
			return (i + 1);
		i++;
	}
	return (0);
}

int	tm_qsort(void)
{
	int	ar_err[3];
	int	tot_err;
	int	i;

	tot_err = 0;
	i = 0;
	while (i < NB_TESTS)
	{
		if (tm_set() == 1)
			tot_err += 1;
		i++;
	}
	if (tot_err != 0)
		return (1);
	ft_qsort(ar_err, 3, sizeof(ar_err[0]), NULL);
	ft_qsort(ar_err, 3, 0, cmp_int);
	ft_qsort(ar_err, 1, sizeof(int), cmp_int);
	ft_qsort(NULL, 3, sizeof(ar_err[0]), cmp_int);
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
