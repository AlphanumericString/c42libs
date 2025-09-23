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

#include "tests/tests_lambda_functions.h"

void	do_nothing(void *data)
{
	(void)data;
}

int	cmp_ptr_as_long(const void *data1, const void *data2)
{
	return ((long)data1 - (long)data2);
}

void	*double_ptr(const void *data)
{
	return ((void *)((long)data * 2));
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
