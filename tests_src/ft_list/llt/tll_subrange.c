/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_subrange.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:44:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/list__ll_tests.h"
#include <stdlib.h>

/*
	ft_ll_push(&list, data); // (42)-> NULL
	ft_ll_push(&list, data2); // (21)-> (42)-> NULL
	sub = ft_ll_subrange(list, list->next); // (21)-> NULL
	sub = ft_ll_subrange(list, NULL); // (21)-> (42)-> NULL
	sub = ft_ll_subrange(list, (const t_list *)data2); // (21)-> (42)-> NULL
*/

int	tll_subrange(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*sub;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	ft_ll_rev(&list);
	sub = ft_ll_subrange(list, list->next);
	if (ft_ll_size(sub) != 1 || sub->data != data2)
		return (ft_ll_delete(&list, ft_free), 1);
	ft_ll_delete(&sub, NULL);
	sub = ft_ll_subrange(list, NULL);
	if (ft_ll_size(sub) != 2 || sub->data != data2 || sub->next->data != data)
		return (ft_ll_delete(&list, ft_free), 2);
	ft_ll_delete(&sub, NULL);
	sub = ft_ll_subrange(list, (const t_list *)data2);
	if (ft_ll_size(sub) != 2 || sub->data != data2 || sub->next->data != data)
		return (ft_ll_delete(&list, ft_free), 3);
	ft_ll_delete(&sub, NULL);
	if (ft_ll_subrange(NULL, NULL))
		return (ft_ll_delete(&list, ft_free), 4);
	sub = ft_ll_subrange(list, list);
	if (ft_ll_size(sub) != 1 || sub->data != data2)
		return (ft_ll_delete(&list, ft_free), 5);
	return (ft_ll_delete(&sub, NULL), ft_ll_delete(&list, ft_free), 0);
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
