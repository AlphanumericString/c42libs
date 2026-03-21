/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:30:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_mem.h"
#include "types/ft_optional_types.h"
#include "tests/fixtures.h"
#include "tests/optional_tests.h"

int	to_dup(void)
{
	t_optional	opt_a;
	t_optional	*opt_b;
	int			prev;

	opt_a.pres = OPT_SOME;
	opt_a.val = (void *)42;
	opt_b = ft_optional_dup(&opt_a);
	if (!opt_b)
		return (1);
	if (opt_b->pres != OPT_SOME)
		return (ft_free(opt_b), 2);
	if (opt_b->val != (void *)42)
		return (ft_free(opt_b), 3);
	ft_free(opt_b);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	opt_b = ft_optional_dup(&opt_a);
	talloc_set_failpoint(prev);
	if (opt_b)
		return (ft_free(opt_b), 4);
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
