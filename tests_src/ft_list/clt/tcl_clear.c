/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"

//
// static void	clnode_print(t_clist *node)
// {
// 	printf("%p(%ld)\t%p(%ld)\t%p(%ld)\n",
// 		node->prev, (long)node->prev->data,
// 		node, (long)node->data,
// 		node->next, (long)node->next->data);
// }

int	tcl_clear(void)
{
	t_clist	*lst;
	size_t	size;

	lst = NULL;
	size = ft_cl_clear(&lst, NULL);
	if (size != 0 || lst != NULL)
		return (1);
	lst = ft_cl_new();
	if (!lst)
		return (2);
	size = ft_cl_clear(&lst, NULL);
	if (size != 1 || lst == NULL || lst->data != NULL)
		return (ft_cl_delete(&lst, NULL), 3);
	ft_cl_delete(&lst, NULL);
	lst = a_to_cl((int []){1, 2, 3}, 3);
	size = ft_cl_clear(&lst, NULL);
	if (size != 3 || lst == NULL || lst->data != NULL
		|| lst->next->data != NULL || lst->prev->data != NULL)
		return (ft_cl_delete(&lst, NULL), 4);
	ft_cl_delete(&lst, NULL);
	lst = a_to_cl((int []){1, 2}, 2);
	size = ft_cl_clear(&lst, do_nothing);
	if (size != 2 || lst == NULL || lst->data != NULL)
		return (ft_cl_delete(&lst, NULL), 5);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_clear_range(void)
{
	t_clist	*lst;
	t_clist	*start;
	t_clist	*end;

	if (ft_cl_clear_range(NULL, NULL, NULL) != 0)
		return (1);
	lst = ft_cl_new();
	if (ft_cl_clear_range(lst, NULL, NULL) != 1)
		return (ft_cl_delete(&lst, NULL), 2);
	ft_cl_delete(&lst, NULL);
	lst = a_to_cl((int []){1, 2, 3, 4}, 4);
	start = lst->next;
	end = lst->prev;
	if (ft_cl_clear_range(start, end, NULL) != 2)
		return (ft_cl_delete(&lst, NULL), 3);
	ft_cl_delete(&lst, NULL);
	lst = a_to_cl((int []){1, 2, 3}, 3);
	if (ft_cl_clear_range(lst, lst->next, do_nothing) != 1
		|| lst == NULL || lst->data != NULL)
		return (ft_cl_delete(&lst, NULL), 4);
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
