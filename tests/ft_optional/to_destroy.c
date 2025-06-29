/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:30:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "types/ft_optional_types.h"
#include "tests/tests__all_modules_tests.h"

int	to_destroy(void)
{
	t_optional	*opt_a;

	opt_a = ft_optional_new();
	opt_a->val = (void *)42;
	opt_a->pres = OPT_SOME;
	if (ft_optional_destroy(opt_a) != false)
		return (1);
	if (opt_a->pres != OPT_SOME)
		return (2);
	if (opt_a->val != (void *)42)
		return (3);
	opt_a->pres = OPT_NONE;
	if (ft_optional_destroy(opt_a) != true)
		return (4);
	if (ft_optional_destroy(NULL) != false)
		return (5);
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
