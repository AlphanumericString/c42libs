/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 23:30:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 23:30:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/lists_test_utils.h"
#include "tests/tests__all_modules_tests.h"

int	tcl_pop(void)
{
	t_clist	*lst;
	void	*data;

	lst = NULL;
	data = ft_cl_pop(NULL);
	if (data != NULL)
		return (1);
	data = ft_cl_pop(&lst);
	if (data != NULL || lst != NULL)
		return (2);
	lst = ft_cl_create((void *)42);
	data = ft_cl_pop(&lst);
	if (data != (void *)42 || lst != NULL)
		return (3);
	lst = a_to_cl((int []){44, 43, 42}, 3);
	data = ft_cl_pop(&lst);
	if (data != (void *)44 || lst->data != (void *)43)
		return (4);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_pop_back(void)
{
	t_clist	*lst;
	void	*data;

	lst = NULL;
	data = ft_cl_pop_back(NULL);
	if (data != NULL)
		return (1);
	data = ft_cl_pop_back(&lst);
	if (data != NULL || lst != NULL)
		return (2);
	lst = ft_cl_create((void *)42);
	data = ft_cl_pop_back(&lst);
	if (data != (void *)42 || lst != NULL)
		return (3);
	lst = a_to_cl((int []){44, 43, 42}, 3);
	data = ft_cl_pop_back(&lst);
	if (data != (void *)42 || lst->data != (void *)44)
		return (4);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
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
