/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_unwrap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:32:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_optional.h"
#include "types/ft_optional_types.h"
#include "tests/optional_tests.h"

int	to_unwrap(void)
{
	t_optional	opt;
	int			*ptr;

	opt.pres = OPT_SOME;
	ptr = ft_malloc(sizeof(int));
	*ptr = 42;
	opt.val = ptr;
	if (ft_optional_unwrap(opt) != ptr)
		return (1);
	ft_free(ptr);
	opt.pres = OPT_NONE;
	opt.val = (void *)0xDEADBEEF;
	if (ft_optional_unwrap(opt) != NULL)
		return (2);
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
