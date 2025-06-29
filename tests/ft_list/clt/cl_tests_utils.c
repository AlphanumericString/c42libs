/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_tests_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:31:35 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 16:31:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "types/ft_list_types.h"
#include <stddef.h>

void	add42_clnode(t_clist *node)
{
	if (node->data)
		add42(node->data);
}

t_clist	*a_to_cl(int *arr, size_t size)
{
	t_clist	*ret;
	size_t	i;

	i = 0;
	ret = NULL;
	while (i < size)
		if (ft_cl_push_back(&ret, (void *)((long)arr[i++])) == NULL)
			return (ft_cl_delete(&ret, NULL), NULL);
	return (ret);
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
