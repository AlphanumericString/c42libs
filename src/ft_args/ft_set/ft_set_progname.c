/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_progname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:00:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 23:24:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "internal/args_helper.h"

#include <pthread.h>
#include <stddef.h>

static const char	*singleton_progname(const char *progname)
{
	static pthread_mutex_t	progname_lock = PTHREAD_MUTEX_INITIALIZER;
	static const char		*singleton_progname = NULL;
	const char				*ret;

	if (FT_THREADS)
		pthread_mutex_lock(&progname_lock);
	if (progname)
		singleton_progname = progname;
	ret = singleton_progname;
	if (FT_THREADS)
		pthread_mutex_unlock(&progname_lock);
	return (ret);
}

void	ft_set_progname(const char *progname)
{
	if (progname)
		singleton_progname(progname);
	else
		singleton_progname("a.out");
}

const char	*ft_progname(void)
{
	return (singleton_progname(NULL));
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
