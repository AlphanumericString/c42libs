/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:29:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "types/ft_optional_types.h"
#include "tests/optional_tests.h"
#include <stdlib.h>

int	to_copy(void)
{
	int			*ptr;
	t_optional	opt_a;
	t_optional	opt_b;

	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt_a.pres = OPT_SOME;
	opt_a.val = ptr;
	ft_optional_copy(&opt_b, &opt_a);
	if (opt_b.pres != OPT_SOME)
		return (1);
	if (*(int *)opt_b.val != 42)
		return (2);
	free(ptr);
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
