/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:40:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 23:24:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_defs.h"
#include "internal/args_helper.h"

#include <pthread.h>
#include <stdlib.h>

static int	ft_ac_singleton(int ac)
{
	static pthread_mutex_t	ac_lock = PTHREAD_MUTEX_INITIALIZER;
	static int				ac_st = 0;
	int						ret;

	if (FT_THREADS)
		pthread_mutex_lock(&ac_lock);
	if (ac >= 0)
		ac_st = ac;
	ret = ac_st;
	if (FT_THREADS)
		pthread_mutex_unlock(&ac_lock);
	return (ret);
}

int	ft_set_ac(int ac)
{
	return (ft_ac_singleton(ac), EXIT_SUCCESS);
}

int	ft_ac(void)
{
	return (ft_ac_singleton(-1));
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
