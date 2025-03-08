/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:18:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args_types.h"
#include "ft_math.h"
#include "ft_string.h"
#include <sys/types.h>

ssize_t	parse_short_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;

	i = 0;
	while (opt_list[i].func)
	{
		if (opt_list[i].short_name && \
		opt_list[i].short_name == str_op[0])
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	parse_long_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;
	ssize_t	offset;

	i = 0;
	offset = 0;
	if (ft_strchr(str_op, '='))
		offset = ft_strchr(str_op, '=') - str_op;
	while (opt_list[i].func)
	{
		if (opt_list[i].long_name && ft_strncmp(opt_list[i].long_name, str_op, \
			ft_max(offset, ft_strlen(opt_list[i].long_name))) == 0)
			return (i);
		i++;
	}
	return (-1);
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
