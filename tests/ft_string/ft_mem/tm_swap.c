/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:20:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests__all_modules_tests.h"
#include "ft_string.h"

/*
	// ignore warning for memset args
	#pragma clang diagnostic pop
*/

int	tm_swap(void)
{
	const int	pair_og[2] = {1, 2};
	const int	*pair[2];
	const int	*pair2[2] = {&pair_og[1], &pair_og[0]};

	pair[0] = &pair_og[0];
	pair[1] = &pair_og[1];
	ft_swap((void **)&pair[0], (void **)&pair[1]);
	if (pair[0] != pair2[0] || pair[1] != pair2[1])
		return (1);
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
