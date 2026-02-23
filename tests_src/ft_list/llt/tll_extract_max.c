/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_extract_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:28:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/05 22:28:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "tests/list__ll_tests.h"
#include "types/ft_list_types.h"

int	tll_extract_max(void)
{
	const char	*strs[] = {"hello", "world", "42", "school", NULL};
	t_list		*list;
	size_t		i;
	void		*ret;

	list = NULL;
	if (ft_ll_extract_max(list, NULL) != NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (strs[i])
		ft_ll_push_back(&list, (void *)strs[i++]);
	if (ft_ll_extract_max(list, NULL) != NULL)
		return (2);
	ret = ft_ll_extract_max(list, (t_data_cmp)ft_strcmp);
	if (!ret || ft_strcmp((char *)ret, "world") != 0)
		return (3);
	ft_ll_clear(&list, NULL);
	return (EXIT_SUCCESS);
}

int	tll_extract_max_node(void)
{
	const char	*strs[] = {"hello", "world", "42", "school", NULL};
	t_list		*list;
	t_list		*ret;
	size_t		i;

	list = NULL;
	if (ft_ll_extract_max_node(list, NULL) != NULL)
		return (1);
	i = 0;
	while (strs[i])
		ft_ll_push_back(&list, (void *)strs[i++]);
	if (ft_ll_extract_max_node(list, NULL) != NULL)
		return (2);
	ret = ft_ll_extract_max_node(list, (t_data_cmp)ft_strcmp);
	if (!ret || ft_strcmp(ret->data, "world") != 0)
		return (3);
	ft_ll_clear(&list, NULL);
	return (EXIT_SUCCESS);
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
