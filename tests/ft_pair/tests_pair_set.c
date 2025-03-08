/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pair_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:09:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:41:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include "tests/pair_tests.h"

int	test_pair_set(void)
{
	t_pair	pair;
	void	*a;
	void	*b;
	void	*c;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADDEAD;
	c = (void *)0xDEADCAFE;
	ft_pair_set(&pair, a, b);
	if (pair.first != a || pair.second != b)
		return (1);
	ft_pair_set(&pair, c, a);
	if (pair.first != c || pair.second != a)
		return (1);
	ft_pair_set(NULL, a, b);
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
