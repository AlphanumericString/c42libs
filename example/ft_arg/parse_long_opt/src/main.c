/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:55:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:20:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "../include/example.h"
#include "../include/usr_strct.h"

#include "ft_args.h"
#include "ft_types.h"
#include "types/ft_args_types.h"
#include "ft_string.h"

static void	printf_user_struct(t_usr_struct data)
{
	ft_print_fd(STDOUT_FILENO, "fields are:\n");
	ft_print_fd(STDOUT_FILENO, "int_val: %d\n", data.int_val);
	ft_print_fd(STDOUT_FILENO, "long_val: %ld\n", data.long_val);
	ft_print_fd(STDOUT_FILENO, "float_val: %f\n", data.float_val);
	ft_print_fd(STDOUT_FILENO, "double_val: %lf\n", data.double_val);
	ft_print_fd(STDOUT_FILENO, "string_val: %s\n", data.string_val);
	if (data.bool_val)
		ft_print_fd(STDOUT_FILENO, "bool_val: %s\n", "true");
	else
		ft_print_fd(STDOUT_FILENO, "bool_val: %s\n", "false");
}

static int	print_y(void *usr)
{
	(void)usr;
	printf("y\n");
	return (0);
}

// not abi stable.........
// but you CAN do it...
static int	print_z(void)
{
	printf("z\n");
	return (0);
}

static t_opt	*opt_list_holder(void)
{
	static t_opt	opt_list[] = {
	{"int", 'i', (void *)lc_opt_int,				FT_AT_INT, "Sets a int."},
	{"version", 'v', (void *)print_long_version,	FT_AH_NO,
		"Display version."},
	{NULL, 'z', (void*)print_z,						FT_AH_NO, "Display y."},
	{NULL, 'y', (void*)print_y,						FT_AH_NO, "Display z."},
	{"long", 'l', (void *)lc_opt_long,				FT_AT_LONG,
		"Sets a long."},
	{"float", 'f', (void *)lc_opt_float,			FT_AT_FLOAT,
		"Sets a float."},
	{"double", 'd', (void *)lc_opt_double,			FT_AT_DOUBLE,
		"Sets an double."},
	{"string", 's', (void *)lc_opt_string,			FT_AH_MAYBE | FT_AT_STR,
		"Sets a string."},
	{"bool", 'b', (void *)lc_opt_bool,				FT_AS_EQSIGN | FT_AT_BOOL,
		"Sets a bool."},
	{NULL, 0, NULL, 0, NULL}
	};

	return (opt_list);
}

int	main(int ac, const char *const *av)
{
	const t_opt		*opt_list = opt_list_holder();
	t_usr_struct	data;
	size_t			i;

	ft_set_opt_list(opt_list);
	ft_bzero(&data, sizeof(t_usr_struct));
	if (ft_parse_args((const char **)av, &data) == EXIT_FAILURE)
		return (
			ft_print_fd(STDERR_FILENO,
				"Error: %s: failed to parse arguments\n", __func__),
			EXIT_FAILURE);
	printf_user_struct(data);
	i = ft_get_nbparg();
	ft_print_fd(STDOUT_FILENO, "\nv2_parse_arg 'ate' %u element(s) !\n",
		(t_uint) i);
	if ((int)i == ac)
		return (ft_print_fd(STDOUT_FILENO, "\nno remainer args, see remainer "
				"args run with stuff after options's end\n"), EXIT_SUCCESS);
	printf_reaminer_args(av, i);
	ft_print_fd(STDOUT_FILENO, "\nYou can also just shift args:\n");
	ft_shift_args((const char *const **)&av, &ac, ft_get_nbparg());
	printf_reaminer_args(av, 0);
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
