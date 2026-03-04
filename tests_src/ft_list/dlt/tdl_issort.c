/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_issort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:20:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/10 14:20:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__dl_tests.h"

static void	push_arr(t_dlist **list, size_t *i, const char **arr)
{
	*list = NULL;
	*i = 0;
	while (arr[*i])
		ft_dl_push(list, (t_any)arr[(*i)++]);
}

static bool	cmp_all(const t_dlist *lst, bool exp[3])
{
	if (ft_dl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != exp[0]
		|| (ft_dl_issort(lst, (t_any)ft_strcmp, 0)
			!= ft_dl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC))
		|| ft_dl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_DES) != exp[1]
		|| ft_dl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_UNO) != exp[2])
		return (true);
	return (false);
}

int	tdl_issort(void)
{
	const char	*arr[] = {"non", "ordered", "array", "for", "test", NULL};
	t_dlist		*lst_fwd;
	t_dlist		*lst_bwd;
	size_t		i;

	(push_arr(&lst_fwd, &i, arr), push_arr(&lst_bwd, &i, arr));
	if (cmp_all(lst_fwd, (bool [3]){false, false, true}) != false)
		return (1);
	ft_dl_sort(&lst_fwd, (t_data_cmp)ft_strcmp, FT_SORT_ORD_ASC);
	ft_dl_sort(&lst_bwd, (t_data_cmp)ft_strcmp, FT_SORT_ORD_DES);
	if (cmp_all(lst_fwd, (bool [3]){true, false, true}) != false
		|| cmp_all(lst_bwd, (bool [3]){false, true, true}) != false)
		return (2);
	if (ft_dl_issort(lst_fwd, NULL, FT_SORT_ORD_ASC) != false
		|| ft_dl_issort(lst_bwd, NULL, FT_SORT_ORD_ASC) != false)
		return (3);
	(ft_dl_delete(&lst_fwd, NULL), ft_dl_delete(&lst_bwd, NULL));
	ft_dl_push(&lst_fwd, (t_any)"single");
	if (cmp_all(lst_bwd, (bool [3]){true, true, true}) != false
		|| cmp_all(lst_fwd, (bool [3]){true, true, true}) != false)
		return (4);
	return (ft_dl_delete(&lst_fwd, NULL), EXIT_SUCCESS);
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
