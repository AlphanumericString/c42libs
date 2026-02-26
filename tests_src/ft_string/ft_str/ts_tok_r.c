/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_tok_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:24:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/18 15:10:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

static int	err_tests(void)
{
	char		*sptr;

	sptr = NULL;
	if (ft_strtok_r(NULL, ":", &sptr) != NULL)
		return (1 + 32);
	if (ft_strtok_r(NULL, ":", NULL) != NULL)
		return (2 + 32);
	return (EXIT_SUCCESS);
}

int	ts_tok_r(void)
{
	char	test[128];
	char	lorem[128];
	char	*sp1;
	char	*token;

	ft_strlcpy(lorem, "Lorem ipsum dolor ", sizeof(lorem));
	ft_strlcpy(test, ":::path/to/file:::another/path::yet/:/another/path",
		sizeof(test));
	if (ft_strcmp(ft_strtok_r(lorem, " ", &sp1), "Lorem") != 0)
		return (1);
	token = (ft_strtok_r(NULL, " ", &sp1), ft_strtok_r(NULL, " ", &sp1));
	if (ft_strcmp(token, "dolor") != 0)
		return (2);
	token = (ft_strtok_r(NULL, " ", &sp1), ft_strtok_r(NULL, " ", &sp1));
	if (token || sp1 != NULL
		|| ft_strcmp(ft_strtok_r(test, ":", &sp1), "path/to/file") != 0)
		return (4);
	token = (ft_strtok_r(NULL, ":", &sp1), ft_strtok_r(NULL, ":", &sp1));
	if (ft_strcmp(token, "yet/") != 0)
		return (5);
	(ft_strtok_r(NULL, ":", &sp1), ft_strtok_r(NULL, ":", &sp1),
		ft_strtok_r(NULL, ":", &sp1));
	if (ft_strtok_r(NULL, ":", &sp1) != NULL)
		return (6);
	return (err_tests());
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
