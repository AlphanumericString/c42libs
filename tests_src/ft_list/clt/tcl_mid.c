/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_mid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2026/01/04 22:31:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/list__cl_tests.h"

int	tcl_mid(void)
{
	t_clist		*lst;
	t_clist		*got[4];
	const void	*exp[4] = {NULL, (t_any)0xDEAD, (t_any)0xDEAD, (t_any)0xCAFE};

	lst = NULL;
	got[0] = ft_cl_mid(lst);
	ft_cl_push(&lst, (t_any)0xDEAD);
	got[1] = ft_cl_mid(lst);
	ft_cl_push(&lst, (t_any)0xCAFE);
	got[2] = ft_cl_mid(lst);
	ft_cl_push(&lst, (t_any)0xBEEF);
	got[3] = ft_cl_mid(lst);
	if (got[0] != exp[0])
		return (ft_cl_delete(&lst, NULL), 1);
	if (got[1]->data != exp[1])
		return (ft_cl_delete(&lst, NULL), 2);
	if (got[2]->data != exp[2])
		return (ft_cl_delete(&lst, NULL), 3);
	if (got[3]->data != exp[3])
		return (ft_cl_delete(&lst, NULL), 4);
	return (ft_cl_delete(&lst, NULL), 0);
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
