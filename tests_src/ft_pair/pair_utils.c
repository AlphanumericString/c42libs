/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:44:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/12 21:44:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "tests/pair_tests.h"

void	triple_pair_setup(t_pair *first, t_pair *diff, t_pair *same_diffloc)
{
	void	*a;
	void	*b;
	void	*c;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADDEAD;
	c = (void *)0xDEADCAFE;
	ft_pair_set(first, a, b);
	ft_pair_set(diff, c, a);
	ft_pair_set(same_diffloc, a, b);
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
