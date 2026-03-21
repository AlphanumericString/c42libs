/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:36:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/10 14:47:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__cl_tests.h"

static void	push_arr(t_clist **list, size_t *i, const char **arr)
{
	*list = NULL;
	*i = 0;
	while (arr[*i])
		ft_cl_push(list, (t_any)arr[(*i)++]);
}

int	tcl_sort(void)
{
	const char	*arr[] = {"non", "ordered", "array", "for", "test", NULL};
	t_clist		*lst;
	size_t		i;

	lst = NULL;
	if (ft_cl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != NULL
		|| ft_cl_sort(NULL, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != NULL)
		return (1);
	push_arr(&lst, &i, arr);
	if (ft_cl_sort(&lst, NULL, FT_SORT_ORD_ASC) != NULL
		|| ft_cl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_UNO) != lst)
		return (ft_cl_delete(&lst, NULL), 2);
	if ((ft_cl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) == NULL
			|| ft_cl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != true)
		|| (ft_cl_sort(&lst, (t_any)ft_strcmp, 0) == NULL
			|| ft_cl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != true))
		return (ft_cl_delete(&lst, NULL), 3);
	if (ft_cl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_DES) == NULL
		|| ft_cl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_DES) != true)
		return (ft_cl_delete(&lst, NULL), 4);
	ft_cl_delete(&lst, NULL);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
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
