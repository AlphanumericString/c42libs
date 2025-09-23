/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_from_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:30:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "types/ft_optional_types.h"
#include "ft_mem.h"
#include "tests/fixtures.h"
#include "tests/optional_tests.h"
#include <stdlib.h>

int	to_from_val(void)
{
	int			*ptr;
	t_optional	*opt;
	int			prev;

	ptr = ft_malloc(sizeof(int));
	*ptr = 42;
	opt = ft_optional_from_val(ptr);
	if (!opt || !opt->val || opt->val != ptr)
		return (ft_free(ptr), ft_free(opt), 1);
	if (opt->pres != OPT_SOME)
		return (ft_optional_destroy(opt), ft_free(ptr), 2);
	opt->pres = OPT_NONE;
	ft_optional_destroy(opt);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_optional_from_val(ptr))
		return (talloc_set_failpoint(prev), 3);
	talloc_set_failpoint(prev);
	ft_free(ptr);
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
