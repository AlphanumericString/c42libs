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

#include "ft_string.h"

#include "tests/argp_tests.h"

int	set_digit(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->nbr = ft_atoi(arg);
	return (0);
}

int	set_int(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->i_nbr = ft_atoi(arg);
	return (0);
}

int	set_long(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->l_nbr = ft_atol(arg);
	return (0);
}

int	set_hex2(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	if (!arg)
		my->hex2 = 0xDEADBEEF;
	else
		my->hex2 = 0xCAFE;
	return (0);
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
	ft_str_replace_chr(tmp, 'a', 'A');
	ft_str_replace_chr(tmp, 'b', 'B');
	ft_str_replace_chr(tmp, 'c', 'C');
	ft_str_replace_chr(tmp, 'd', 'D');
	ft_str_replace_chr(tmp, 'e', 'E');
	ft_str_replace_chr(tmp, 'f', 'F');
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
