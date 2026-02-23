/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targp_usrt_bindings_utils1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:16:44 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 19:16:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"
#include "ft_mem.h"

#include "tests/argp_tests.h"

int	set_digit(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->nbr = ft_atoi(arg);
	return (EXIT_SUCCESS);
}

int	set_int(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->i_nbr = ft_atoi(arg);
	return (EXIT_SUCCESS);
}

int	set_long(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->l_nbr = ft_atol(arg);
	return (EXIT_SUCCESS);
}

int	set_hex2(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	if (!arg)
		my->hex2 = 0xDEADBEEF;
	else
		my->hex2 = 0xCAFE;
	return (EXIT_SUCCESS);
}

int	set_hex(void *user_struct, const char *arg)
{
	t_usr	*my;
	char	*tmp;

	my = user_struct;
	if (!arg)
		return (my->hex = 0xDEADBEEF, 0);
	if (arg[0] == '0' && arg[1] == 'x')
		tmp = ft_strdup(arg + 2);
	else
		tmp = ft_strdup(arg);
	if (!tmp)
		return (1);
	ft_strrpl_chrs(tmp, FT_HEXBASE, FT_HEXBASE_CAP);
	my->hex = ft_atol_base(tmp, FT_HEXBASE_CAP);
	return (ft_free(tmp), 0);
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
