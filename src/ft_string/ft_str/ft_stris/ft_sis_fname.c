/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sis_fname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:15:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 23:34:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "ft_stris.h"
#include <stddef.h>
#include <linux/limits.h>

bool	ft_str_ispath(const char *path)
{
	size_t	i;
	size_t	len;

	if (!path || !*path)
		return (false);
	i = 0;
	len = 0;
	while (path[i])
	{
		len = ft_strclen(path + i, '/');
		if (len > NAME_MAX || len + i > PATH_MAX)
			return (false);
		i += (len + path[i + len] != '\0');
	}
	return (true);
}

bool	ft_str_isfname(const char *fname)
{
	size_t	i;

	if (!fname || !*fname)
		return (false);
	i = ft_strclen(fname, '/');
	return (!(fname[i] || i > NAME_MAX));
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
