/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_nbparg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 04:24:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/12 13:47:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_args.h"
#include "internal/args_helper.h"
#include "pthread.h"

static size_t	*singleton_nbparg(size_t nb_, bool set)
{
	static pthread_mutex_t	nb_lock = PTHREAD_MUTEX_INITIALIZER;
	static size_t			nb = 0;
	size_t					*ret;

	if (FT_THREADS)
		pthread_mutex_lock(&nb_lock);
	if (set)
		nb = nb_;
	ret = &nb;
	if (FT_THREADS)
		pthread_mutex_unlock(&nb_lock);
	return (ret);
}

void	ft_set_nbparg(size_t nb)
{
	singleton_nbparg(nb, true);
}

size_t	ft_get_nbparg(void)
{
	return (*singleton_nbparg(0, false));
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
