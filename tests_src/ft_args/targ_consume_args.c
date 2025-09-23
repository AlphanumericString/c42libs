/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_consume_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 02:38:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "tests/args_tests.h"

int	targ_consume_args_test(void)
{
	const char	**tmp = NULL;
	const char	**test;
	int			fake_argc;
	const char	*ret;
	const char	*fake_args[] = {"test", "1", "2", "3", "4", NULL};

	test = fake_args;
	ret = NULL;
	fake_argc = 5;
	ret = ft_consume_args(&test, &fake_argc);
	if (fake_argc != 4 || ft_strcmp(test[0], "1") != 0
		|| ft_strcmp(test[1], "2") != 0 || ft_strcmp(test[2], "3") != 0
		|| ft_strcmp(test[3], "4") != 0 || ft_strcmp(ret, "test") != 0)
		return (1);
	(ft_consume_args(&test, &fake_argc), ft_consume_args(&test, &fake_argc),
		ft_consume_args(&test, &fake_argc), ft_consume_args(&test, &fake_argc));
	ret = ft_consume_args(&test, &fake_argc);
	if (fake_argc != 0 || ret)
		return (2);
	fake_argc = 4012;
	if (ft_consume_args(&test, &fake_argc) || ft_consume_args(&tmp, &fake_argc))
		return (3);
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
