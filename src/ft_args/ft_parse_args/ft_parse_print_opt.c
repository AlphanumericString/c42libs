/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_print_opt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:39:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:42:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		if (ls[i].desc)
//			tabwidth - getenv TAB_WIDTH else 8;
//			ioctl - get term width
//			print by chunk of (width - 3*tabwidth)
//			set in buffer
// TODO:
// maybe expose to pulic if they do their own help function?
#include "ft_string.h"
#include "internal/args_helper.h"

void	print_opt(const t_opt opt, int fd)
{
	if (!opt.long_name && !opt.short_name)
		return ;
	if (opt.long_name)
		(ft_print_fd(fd, "\t--%s", opt.long_name),
			put_type_fd(opt.type, fd));
	if (opt.short_name)
		(ft_print_fd(fd, "\t-%c", opt.short_name),
			put_type_fd(opt.type, fd));
	if (opt.desc)
		ft_print_fd(fd, "\n\t\t%s\n", opt.desc);
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
