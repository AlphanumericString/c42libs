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

// TODO: (problematic due to sys call function restriction @ 42)
//		if (ls[i].desc)
//			tabwidth - getenv TAB_WIDTH else 8;
//			ioctl - get term width
//			print by chunk of (width - 3*tabwidth)
//			set in buffer
#include "ft_string.h"
#include "internal/args_helper.h"
#include "ft_args.h"

static void	print_desc(const char *d, int fd)
{
	ft_print_fd(fd, "\n\t\t%s\n", d);
}

void	ft_print_opts(const t_opt opt, int fd)
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
		print_desc(opt.desc, fd);
	else
		ft_print_fd(fd, "\n");
}

void	ft_print_fopts(const t_opt *opt, int fd)
{
	unsigned int	i;

	i = 0;
	while (opt[i].func)
		ft_print_opts(opt[i++], fd);
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
