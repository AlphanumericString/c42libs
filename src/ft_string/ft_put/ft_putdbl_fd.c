/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:38:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/12 16:27:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "ft_defs.h"
#include "ft_string.h"
#include "ft_char.h"
#include "ft_math.h"

const char	*flt_spevals(bool maj, double val)
{
	const char	*spevals[2][3] = {
	{"inf", "nan", "-inf"},
	{"INF", "NAN", "-INF"}
	};

	if (val == INFINITY)
		return (spevals[maj][0]);
	if (val == -INFINITY)
		return (spevals[maj][2]);
	if (val != val)
		return (spevals[maj][1]);
	return (NULL);
}

int	ft_putdbl_fd(double value, int fd)
{
	int		result;
	int		total;

	total = 0;
	if (flt_spevals(false, value))
		return (ft_putstr_fd(flt_spevals(false, value), fd));
	if (value < 0)
	{
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		value = -value;
		total++;
	}
	result = ft_putnbr_base_fd((ssize_t)value, "0123456789", fd);
	if (result < 0)
		return (-1);
	total += result;
	result = ft_putchar_fd('.', fd);
	if (result < 0)
		return (-1);
	total += result;
	value -= (ssize_t)value;
	value = ft_round(value * 1000000);
	return (ft_putnbr_base_fd((ssize_t)(value), "0123456789", fd) + total);
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
