/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:58:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:10:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/example.h"
#include "../include/usr_strct.h"

#include "ft_string.h"

#include <unistd.h>

int	lc_opt_int(t_usr_struct *data, const char *arg)
{
	if (!ft_str_isint(arg))
		return (ft_print_fd(STDERR_FILENO, "not int: %s\n", arg), -1);
	data->int_val = ft_atoi(arg);
	return (0);
}

int	lc_opt_long(t_usr_struct *data, const char *arg)
{
	if (!ft_str_islong(arg))
		return (ft_print_fd(STDERR_FILENO, "not long: %s\n", arg), -1);
	data->long_val = ft_atol(arg);
	return (0);
}

int	lc_opt_float(t_usr_struct *data, const char *arg)
{
	if (!ft_str_isfloat(arg))
		return (ft_print_fd(STDERR_FILENO, "not float: %s\n", arg), -1);
	data->float_val = (float)ft_atod(arg);
	return (0);
}

int	lc_opt_double(t_usr_struct *data, const char *arg)
{
	if (!ft_str_isdouble(arg))
		return (ft_print_fd(STDERR_FILENO, "not double: %s\n", arg), -1);
	data->double_val = ft_atod(arg);
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
