/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:40:21 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/12 16:30:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "internal/print.h"
#include "ft_string.h"
#include <stdio.h>

int	flt_processor(va_list args, int fd)
{
	double	value;

	value = va_arg(args, double);
	if (flt_spevals(false, value))
		return (ft_putstr_fd(flt_spevals(false, value), fd));
	return (ft_putdbl_fd(value, fd));
}

int	flt_upper_processor(va_list args, int fd)
{
	double	value;

	value = va_arg(args, double);
	if (flt_spevals(true, value))
		return (ft_putstr_fd(flt_spevals(true, value), fd));
	return (ft_putdbl_fd(value, fd));
}

static double	exponent_handler(double value, int *exp)
{
	*exp = 0;
	while (value >= 10.0 || value <= -10.0)
	{
		value /= 10.0;
		(*exp)++;
	}
	while ((value < 1.0 && value > 0.0) || (value > -1.0 && value < 0.0))
	{
		value *= 10.0;
		(*exp)--;
	}
	return (value);
}

int	exp_processor(va_list args, int fd)
{
	double	value;
	char	exp_str[5];
	int		exp;
	int		ret;

	value = va_arg(args, double);
	if (flt_spevals(false, value))
		return (ft_putstr_fd(flt_spevals(false, value), fd));
	value = exponent_handler(value, &exp);
	ret = ft_putdbl_fd(value, fd);
	if (ret < 0)
		return (-1);
	ft_strlcpy(exp_str, "e+00", sizeof(exp_str));
	exp_str[1] = '-' * (exp < 0) + '+' * (exp >= 0);
	exp = ft_abs(exp);
	exp_str[2] = ((exp / 10) % 10) + '0';
	exp_str[3] = (exp % 10) + '0';
	if (ft_putstr_fd(exp_str, fd) < 0)
		return (-1);
	return (ret + 4);
}

int	exp_upper_processor(va_list args, int fd)
{
	double	value;
	char	exp_str[5];
	int		exp;
	int		ret;

	value = va_arg(args, double);
	if (flt_spevals(true, value))
		return (ft_putstr_fd(flt_spevals(true, value), fd));
	value = exponent_handler(value, &exp);
	ret = ft_putdbl_fd(value, fd);
	if (ret < 0)
		return (-1);
	ft_strlcpy(exp_str, "E+00", sizeof(exp_str));
	exp_str[1] = '-' * (exp < 0) + '+' * (exp >= 0);
	exp = ft_abs(exp);
	exp_str[2] = (exp / 10) + '0';
	exp_str[3] = (exp % 10) + '0';
	if (ft_putstr_fd(exp_str, fd) < 0)
		return (-1);
	return (ret + 4);
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
