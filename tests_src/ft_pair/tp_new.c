/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:14:03 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "types/ft_pair_types.h"
#include "tests/pair_tests.h"
#include "tests/fixtures.h"

int	tp_new(void)
{
	t_pair	*pair;
	void	*a;
	void	*b;
	int		prev;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADDEAD;
	pair = ft_pair_new(NULL, NULL);
	if (!pair)
		return (1);
	if (pair->first || pair->second)
		return (ft_pair_destroy(&pair, NULL), 2);
	ft_pair_set(pair, a, b);
	if (pair->first != a || pair->second != b)
		return (ft_pair_destroy(&pair, NULL), 3);
	ft_pair_destroy(&pair, NULL);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	pair = ft_pair_new(NULL, NULL);
	talloc_set_failpoint(prev);
	if (pair)
		return (ft_pair_destroy(&pair, NULL), 4);
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
