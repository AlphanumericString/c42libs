/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_optional_from_val.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:30:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"
#include "ft_string.h"
#include "tests/tests.h"
#include "tests/tests__all_modules_tests.h"
#include <stdlib.h>

int	test_optional_from_val(void)
{
	int			*ptr;
	t_optional	*opt;
	int			prev;

	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt = ft_optional_from_val(ptr);
	if (!opt)
		return (1);
	if (opt->pres != OPT_SOME)
		return (2);
	if (opt->val != ptr)
		return (3);
	opt->pres = OPT_NONE;
	ft_optional_destroy(opt);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_optional_from_val(ptr))
		return (4);
	talloc_set_failpoint(prev);
	ft_free(ptr);
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
