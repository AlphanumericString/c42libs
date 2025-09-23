/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:37:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_mem.h"
#include "tests/lists_test_utils.h"
#include "tests/fixtures.h"
#include "tests/list__ll_tests.h"
#include <stdlib.h>

int	t_ll_push(void)
{
	t_list			*list;
	t_list			*list_rep1;
	t_list			*list_rep2;
	int				prev;

	list = NULL;
	list_rep1 = ft_ll_push(&list, (void *)42);
	list_rep2 = ft_ll_push(&list, (void *)84);
	if (!list || !list_rep1 || !list_rep2)
		return (ft_free(list_rep1), ft_free(list_rep2), 1);
	else if (list != list_rep2)
		return (ft_free(list_rep1), ft_free(list_rep2), 2);
	else if (list->next != list_rep1 || ft_ll_size(list) != 2)
		return (ft_free(list_rep1), ft_free(list_rep2), 3);
	else if (list->data != (void *)84 || list->next->data != (void *)42)
		return (ft_free(list_rep1), ft_free(list_rep2), 4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_ll_push(&list, (void *)42))
		return (talloc_set_failpoint(prev), 6);
	talloc_set_failpoint(prev);
	ft_ll_clear(&list, NULL);
	return (ft_ll_push(NULL, NULL), 0);
}

int	t_ll_push_back(void)
{
	t_list	*list;
	int		prev;

	list = NULL;
	ft_ll_push_back(&list, (void *)42);
	ft_ll_push_back(&list, (void *)84);
	if (ft_ll_size(list) != 2)
		return (1);
	else if (list->data != (void *)42)
		return (2);
	else if (list->next->data != (void *)84)
		return (3);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_ll_push_back(&list, (void *)42))
		return (talloc_set_failpoint(prev), 4);
	talloc_set_failpoint(prev);
	ft_ll_clear(&list, NULL);
	return (ft_ll_push_back(NULL, NULL), 0);
}

int	t_ll_pop(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	*pop;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	pop = ft_ll_pop(&list);
	if (!list || ft_ll_size(list) != 1)
		return (1);
	else if (list->data != data2)
		return (2);
	else if (pop != data)
		return (3);
	ft_ll_clear(&list, ft_free);
	ft_free(pop);
	if (ft_ll_pop(&list) || ft_ll_pop(NULL))
		return (4);
	return (EXIT_SUCCESS);
}

/*
	create_2elem_list(&list, (void **)&data, (void **)&data2);
	// (42)-> (21)-> NULL
	data3 = ft_malloc(sizeof(int));
	*data3 = 63;
	ft_ll_push(&list, data3); // (63)-> (42)-> (21)-> NULL
	pop = ft_ll_pop_back(&list); // 21 : (63)-> (42)-> NULL
	if (ft_ll_size(list) != 2)
		return (1);
	else if (list->data != data3)
		return (1);
	else if (list->next->data != data)
		return (1);
	else if (pop != data2)
		return (1);
	pop = ft_ll_pop_back(&list); // 42 : (63)-> NULL

*/
int	t_ll_pop_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	int		*data3;
	void	*pop;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	data3 = ft_malloc(sizeof(int));
	*data3 = 63;
	ft_ll_push(&list, data3);
	pop = ft_ll_pop_back(&list);
	if (ft_ll_size(list) != 2)
		return (1);
	else if (list->data != data3 || list->next->data != data || pop != data2)
		return (2);
	pop = ft_ll_pop_back(&list);
	if (ft_ll_size(list) != 1 || list->data != data3 || pop != data)
		return (3);
	pop = ft_ll_pop_back(&list);
	if (list || pop != data3 || ft_ll_size(list) != 0 || ft_ll_pop_back(&list)
		|| ft_ll_pop_back(NULL))
		return (4);
	return (free(data), free(data2), free(data3), 0);
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
