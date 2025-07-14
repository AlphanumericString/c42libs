/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targp_usrt_bindings_utils2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:16:22 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 19:16:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/argp_tests.h"

int	set_oct(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	if (arg && (arg[0] == '0' && (arg[1] == 'o' || arg[1] == 'O')))
		my->oct = ft_atoi_base(arg + 2, FT_OCTBASE);
	else if (arg)
		my->oct = ft_atoi_base(arg, FT_OCTBASE);
	else
		my->oct = 32;
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
