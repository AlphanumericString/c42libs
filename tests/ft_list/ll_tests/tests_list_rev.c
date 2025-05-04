/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:40:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 14:16:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests__all_modules_tests.h"

#include <stdlib.h>

int	t_ll_rev(void)
{
	t_list	*list;
	t_list	*rev;
	int		*data;
	int		*data2;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	rev = ft_ll_rev(&list);
	if (ft_ll_size(list) != 2)
		return (1);
	else if (rev->data != data2)
		return (1);
	else if (rev->next->data != data)
		return (1);
	ft_ll_clear(&rev, ft_free);
	rev = NULL;
	rev = ft_ll_rev(NULL);
	if (rev || ft_ll_rev(&rev))
		return (1);
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
