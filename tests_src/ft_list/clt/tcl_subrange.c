/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_subrange.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/lists_test_utils.h"
#include "tests/fixtures.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"

static int	mt_clsubrange(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*cl;
	t_clist		*sub;
	int			r;

	r = EXIT_SUCCESS;
	cl = NULL;
	ft_cl_push(&cl, "toto");
	ft_cl_push(&cl, "titi");
	ft_cl_push(&cl, "tutu");
	talloc_set_failpoint(0);
	sub = ft_cl_subrange(cl, cl->prev);
	if (sub)
		r = 1;
	talloc_set_failpoint(fp);
	ft_cl_delete(&cl, NULL);
	return (r);
}

static int	tcl_subrange_partial(t_clist *lst)
{
	t_clist	*subrange;

	subrange = ft_cl_subrange(lst, NULL);
	if (!subrange || ft_cl_size(subrange) != 3
		|| subrange->data != (void *)42
		|| subrange->next->data != (void *)43
		|| subrange->next->next->data != (void *)44)
		return (ft_cl_delete(&subrange, NULL), 4);
	ft_cl_delete(&subrange, NULL);
	subrange = ft_cl_subrange(lst, lst->next->next);
	if (!subrange || ft_cl_size(subrange) != 2
		|| subrange->data != (void *)42
		|| subrange->next->data != (void *)43
		|| subrange->next->next != subrange)
		return (ft_cl_delete(&subrange, NULL), 5);
	return (ft_cl_delete(&subrange, NULL), EXIT_SUCCESS);
}

int	tcl_subrange(void)
{
	t_clist	*lst;
	t_clist	*subrange;
	int		err;

	if (ft_cl_subrange(NULL, NULL) != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	subrange = ft_cl_subrange(lst, NULL);
	if (!subrange || subrange->data != (void *)42 || !lst)
		return (ft_cl_delete(&subrange, NULL), 2);
	ft_cl_delete(&subrange, NULL);
	ft_cl_delete(&lst, NULL);
	lst = a_to_cl((int []){42, 43, 44}, 3);
	subrange = ft_cl_subrange(lst, lst);
	if (!subrange || subrange->next != subrange
		|| subrange->prev != subrange
		|| subrange->data != (void *)42 || lst->data != (void *)42)
		return (ft_cl_delete(&subrange, NULL), 3);
	ft_cl_delete(&subrange, NULL);
	err = tcl_subrange_partial(lst);
	if (err != 0)
		return (err);
	return (ft_cl_delete(&lst, NULL), mt_clsubrange());
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
