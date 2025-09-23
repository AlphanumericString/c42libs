/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 01:51:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "ft_string.h"
#include "ft_math.h"

char	*ft_stoa_base(size_t nbr, const char *base)
{
	char	buff[200];

	if (!base || ft_base_valid(base) != true)
		return (NULL);
	if (ft_stopa_base(nbr, base, (char *)buff, 200) != true)
		return (NULL);
	return (ft_strdup(buff));
}

char	*ft_sstoa_base(ssize_t nbr, const char *base)
{
	char	buff[200];

	if (!base || ft_base_valid(base) != true)
		return (NULL);
	if (ft_sstopa_base(nbr, base, (char *)buff, 200) != true)
		return (NULL);
	return (ft_strdup(buff));
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
