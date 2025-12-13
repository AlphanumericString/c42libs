/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:28:44 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:58:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__ll_tests.h"
#include "types/ft_list_types.h"

static bool	bad_list(t_list *lst, t_data_cmp cmp, int flg, size_t nbr)
{
	if (!lst || ft_ll_size(lst) != nbr || ft_ll_issort(lst, cmp, flg) != true)
		return (true);
	return (false);
}

static void	init(t_list **list, size_t *i, const char **arr, t_data_cmp *cmp)
{
	*list = NULL;
	*i = 0;
	while (arr[*i])
		ft_ll_push(list, (void *)arr[(*i)++]);
	*cmp = (t_data_cmp)ft_strcmp;
}

int	tll_sort(void)
{
	const char	*arr[] = {"hello", "world", "this", "is", "Zod", NULL};
	t_list		*lst;
	t_data_cmp	cmp;
	size_t		i;
	int			flg;

	init(&lst, &i, arr, &cmp);
	flg = FT_SORT_ORD_ASC;
	(ft_ll_sort(&lst, cmp, flg), ft_ll_sort(&lst, cmp, flg));
	if (ft_ll_sort(&lst, cmp, FT_SORT_ORD_UNO) != lst
		|| bad_list(lst, cmp, flg, i))
		return (1);
	flg = FT_SORT_ORD_DES;
	if (ft_ll_sort(&lst, cmp, flg) != lst || bad_list(lst, cmp, flg, i))
		return (2);
	flg = FT_SORT_ORD_ASC;
	if (ft_ll_sort(&lst, cmp, 0) != lst || bad_list(lst, cmp, flg, i))
		return (3);
	ft_ll_delete(&lst, NULL);
	if (ft_ll_sort(&lst, cmp, 0) != NULL || ft_ll_sort(NULL, cmp, 0) != NULL
		|| ft_ll_sort((t_any)0xDEADBEEF, NULL, 0) != NULL)
		return (5);
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
