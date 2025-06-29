/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_shift_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "internal/debug_defs.h"
#include "tests/tests__all_modules_tests.h"
#include <stdio.h>

int	targ_shift_args(void)
{
	char		**_args;
	char		**av;
	char		**p_args;
	int			ac;

	_args = ft_split("pname|a1|a2|a3", '|');
	ac = ft_alen((t_const_arr)_args);
	ft_set_av((void *)_args);
	p_args = _args;
	ft_shift_args((void *)&_args, &ac, 2);
	av = (char **)ft_av();
	if (ac != 2 || ft_strcmp(_args[0], "a2") || av != _args)
		return (ft_afree((t_arr)p_args), 1);
	ft_shift_args((t_any) & _args, &ac, -1);
	ft_shift_args((t_any) NULL, &ac, 1);
	ft_shift_args((t_any) & _args, NULL, 1);
	ft_shift_args((t_any) & _args, &ac, 4);
	_args = NULL;
	ft_shift_args((t_any) & _args, &ac, 2);
	_args = p_args;
	ac = 0;
	ft_shift_args((t_any) & _args, &ac, 2);
	ac = ft_alen((t_const_arr)_args);
	return (ft_shift_args((t_any) & _args, &ac, ac + 1),
		ft_afree((t_arr) p_args), 0);
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
