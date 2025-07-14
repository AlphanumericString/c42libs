/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambdas_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:42:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 13:29:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests_lambda_functions.h"

void	add42(void *data)
{
	int	*ptr;

	ptr = (int *)data;
	*ptr += 42;
}

void	*add42_ret(const void *data)
{
	int	*ret;

	ret = ft_malloc(sizeof(int));
	if (!ret)
		return (NULL);
	*ret = *(int *)data;
	*ret += 42;
	return ((void *)ret);
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
