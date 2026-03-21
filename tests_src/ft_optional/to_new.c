/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:31:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_mem.h"
#include "types/ft_optional_types.h"
#include "tests/fixtures.h"
#include "tests/optional_tests.h"

int	to_new(void)
{
	t_optional	*opt;
	int			prev;

	opt = ft_optional_new();
	if (!opt)
		return (1);
	if (opt->pres != OPT_NONE)
		return (ft_free(opt), 2);
	if (opt->val)
		return (ft_free(opt), 3);
	ft_free(opt);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	opt = ft_optional_new();
	talloc_set_failpoint(prev);
	if (opt)
		return (ft_free(opt), 4);
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
