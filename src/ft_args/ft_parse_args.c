/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:10:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:18:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_args_types.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>

int	run_opt_func(const t_opt opt, void *usr_control_struct, const char **arg, \
				int *i)
{
	const char	*arg_ptr;
	void		(*func_arg)(void *, const char *);
	void		(*func_no_arg)(void *);

	func_arg = opt.func;
	func_no_arg = opt.func;
	if (opt.type & OPT_ARG && opt.type & OPT_EQSIGN)
		arg_ptr = ft_strchr(arg[*i], '=') + 1;
	else if (opt.type & OPT_ARG)
		arg_ptr = arg[*i + 1];
	else
		arg_ptr = NULL;
	if (checker_arg(opt.type, arg_ptr) != 0)
		return (arg_type_err(opt, arg_ptr));
	if (opt.type & OPT_ARG)
		func_arg(usr_control_struct, arg_ptr);
	else
		func_no_arg(usr_control_struct);
	*i += 1 + ((opt.type != 0) && (opt.type & OPT_EQSIGN) == 0);
	return (EXIT_SUCCESS);
}

int	ft_parse_args(const char **argv, void *usr_control_struct)
{
	const t_opt	*opt;
	ssize_t		opt_index;
	int			i;

	opt = ft_get_opt_list();
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (argv[i][1] == '-' && argv[i][2] == '\0')
			return (i + 1);
		else if (argv[i][1] == '-')
			opt_index = parse_long_opt(argv[i] + 2, opt);
		else
			opt_index = parse_short_opt(argv[i] + 1, opt);
		if (opt_index == -1)
			return (arg_opt_err(argv[i]));
		if (run_opt_func(opt[opt_index], usr_control_struct, argv, &i) != 0)
			return (-1);
	}
	return (i);
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
