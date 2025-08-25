/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_av.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:40:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 23:24:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_defs.h"
#include "internal/args_helper.h"

#include <pthread.h>
#include <stdlib.h>

static const char *const	*ft_av_singleton(const char *const *av)
{
	static pthread_mutex_t		av_lock = PTHREAD_MUTEX_INITIALIZER;
	static const char *const	*av_st = NULL;
	const char *const			*ret;

	if (FT_THREADS)
		pthread_mutex_lock(&av_lock);
	if (av)
		av_st = av;
	ret = av_st;
	if (FT_THREADS)
		pthread_mutex_unlock(&av_lock);
	return (ret);
}

int	ft_set_av(const char *const *const av)
{
	if (!av)
		return (EXIT_FAILURE);
	return (ft_av_singleton(av), EXIT_SUCCESS);
}

const char *const	*ft_av(void)
{
	return (ft_av_singleton(NULL));
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
