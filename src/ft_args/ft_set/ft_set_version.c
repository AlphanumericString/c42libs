/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_version.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:57:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 23:24:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_defs.h"
#include "internal/args_helper.h"

#include <stddef.h>

static const char	*singleton_version(const char *version)
{
	static const char	*singleton_version = NULL;

	if (version)
		singleton_version = version;
	return (singleton_version);
}

void	ft_set_version(const char *version)
{
	if (version)
		singleton_version(version);
	else
		singleton_version(VERSION);
	return ;
}

const char	*ft_version(void)
{
	return (singleton_version(NULL));
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
