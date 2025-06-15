/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_custom_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 04:00:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "ft_defs.h"
#include "ft_args.h"
#include "internal/args_helper.h"

static t_data_is	singleton_custom_checker(t_data_is custom_checker)
{
	static t_data_is	custom_checker_ptr = NULL;

	if (custom_checker)
		custom_checker_ptr = custom_checker;
	return (custom_checker_ptr);
}

int	ft_arg_set_custom_checker(t_data_is custom_checker)
{
	if (!custom_checker)
		return (EXIT_FAILURE);
	singleton_custom_checker(custom_checker);
	return (EXIT_SUCCESS);
}

t_data_is	ft_arg_get_custom_checker(void)
{
	return (singleton_custom_checker(NULL));
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
