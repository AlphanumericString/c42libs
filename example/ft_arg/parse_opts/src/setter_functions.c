/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:00:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:06:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "../include/example.h"
#include "../include/usr_strct.h"

#include "ft_string.h"
#include "ft_stris.h"

int	lc_opt_bool(t_usr_struct *data, const char *arg)
{
	if (!ft_str_isbool(arg))
		return (ft_print_fd(STDERR_FILENO, "not boolean: %s\n", arg), -1);
	if (ft_strcmp(arg, "true") == 0 || ft_strcmp(arg, "1") == 0)
		data->bool_val = true;
	else
		data->bool_val = false;
	return (0);
}

int	lc_opt_string(t_usr_struct *data, const char *arg)
{
	if (!arg || !*arg)
	{
		data->string_val = NULL;
		return (ft_print_fd(STDERR_FILENO, "no string\n"), EXIT_SUCCESS);
	}
	data->string_val = (char *)arg;
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
