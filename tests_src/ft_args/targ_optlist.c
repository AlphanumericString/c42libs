/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_optlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/args_helper.h"
#include "ft_args.h"
#include "types/ft_args_types.h"
#include "tests/args_tests.h"
#include <stddef.h>

static void	empty(void *ar, char *arg)
{
	(void)ar;
	(void)arg;
}

int	targ_opt_list_test(void)
{
	static t_opt	op1[] = {
	{"--test", 't', &empty, 0, NULL},
	{NULL, 0, NULL, 0, NULL}
	};

	ft_set_opt_list(op1);
	if (ft_get_opt_list() != op1)
		return (1);
	ft_set_opt_list(NULL);
	if (ft_get_opt_list() != op1)
		return (2);
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
