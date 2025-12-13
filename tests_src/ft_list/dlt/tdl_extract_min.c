/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_extract_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:07:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:52:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__dl_tests.h"
#include <stdio.h>

int	tdl_extract_min(void)
{
	const char	*arr[] = {"looong", "a", "longer", "long", "tiny", NULL};
	t_dlist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_dl_push(&list, (void *)arr[i++]);
	if (ft_dl_extract_min(list, (t_any)ft_strcmp) != (void *)arr[1])
		return (1);
	if (ft_dl_extract_min(NULL, (t_any)ft_strcmp) != NULL
		|| ft_dl_extract_min(list, NULL) != NULL)
		return (2);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
}

int	tdl_extract_min_node(void)
{
	const char	*arr[] = {"looong", "a", "longer", "long", "tiny", NULL};
	t_dlist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_dl_push(&list, (void *)arr[i++]);
	if (ft_dl_extract_min_node(list, (t_any)ft_strcmp)->data != (void *)arr[1])
		return (1);
	if (ft_dl_extract_min_node(NULL, (t_any)ft_strcmp) != NULL
		|| ft_dl_extract_min_node(list, NULL) != NULL)
		return (2);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
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
