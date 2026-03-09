/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_mid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:53:46 by bgoulard          #+#    #+#             */
/*   Updated: 2026/01/03 19:53:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "sys/cdefs.h"
#include "tests/list__ll_tests.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"

int	tll_mid(void)
{
	t_list	*lst = NULL;
	t_list	*res[4];
	const void *exp[4] = { NULL, (t_any)0xDEAD, (t_any)0xCAFE, (t_any)0xCAFE};

	res[0] = ft_ll_mid(lst);
	ft_ll_push(&lst, (t_any)0xDEAD);
	res[1] = ft_ll_mid(lst);
	ft_ll_push(&lst, (t_any)0xCAFE);
	res[2] = ft_ll_mid(lst);
	ft_ll_push(&lst, (t_any)0xBEEF);
	res[3] = ft_ll_mid(lst);
	if (res[0])
		return (1);
	if (res[1]->data != exp[1])
		return (2);
	if (res[2]->data != exp[2])
		return (3);
	if (res[3]->data != exp[2])
		return (4);
	ft_ll_clear(&lst, NULL);
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
