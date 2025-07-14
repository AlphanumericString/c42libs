/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_subrange.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:08 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:05:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_string.h"
#include "tests/lists_test_utils.h"
#include "tests/fixtures.h"
#include "tests/list__dl_tests.h"

static int	base_cases(void)
{
	t_dlist	*list;
	t_dlist	*sub;
	int		*data1;
	int		*data2;
	int		*data3;

	data3 = ft_malloc(sizeof(int));
	*data3 = 63;
	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	ft_dl_push_back(&list, data3);
	sub = ft_dl_subrange(list, list->next);
	if (ft_dl_size(sub) != 1 || sub->data != data1)
		return (1);
	ft_dl_clear(&sub, NULL);
	sub = ft_dl_subrange(list, list->next->next);
	if (ft_dl_size(sub) != 2 || sub->data != data1
		|| sub->next->data != data2 || (ft_dl_clear(&sub, NULL), 0))
		return (2);
	if (ft_dl_subrange(NULL, NULL))
		return (3);
	sub = ft_dl_subrange(list, list);
	if (ft_dl_size(sub) != 1 || sub->data != data1)
		return (4);
	return (ft_dl_clear(&sub, NULL), ft_dl_clear(&list, ft_free), 0);
}

static int	mt_cases(void)
{
	t_dlist		*lists[2];
	int			*_datas[3];
	const int	f_point = *talloc_get_failpoint();
	int			*cur_ap;

	_datas[2] = ft_malloc(sizeof(int));
	*_datas[2] = 63;
	create_2elem_dlist(&lists[0], (void **) &_datas[0], (void **) &_datas[1]);
	ft_dl_push_back(&lists[0], _datas[2]);
	cur_ap = talloc_get_currentpoint();
	talloc_set_failpoint(*cur_ap + 1);
	lists[1] = ft_dl_subrange(lists[0], lists[0]->next->next);
	talloc_set_failpoint(f_point);
	if (lists[1])
		return (ft_dl_clear(&lists[0], ft_free), 1);
	ft_dl_clear(&lists[0], ft_free);
	return (0);
}

int	t_dl_subrange(void)
{
	int	ret;

	ret = base_cases();
	if (ret)
		return (ret);
	ret = mt_cases();
	if (ret)
		return (ret + 10);
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
