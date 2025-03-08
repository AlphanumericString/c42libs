/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:09:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:33:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_char.h"

static int	loc_forward(const char *str, int *i)
{
	bool	neg;

	neg = false;
	*i = 0;
	while (ft_isspace(str[*i]) || str[*i] == '-' || str[*i] == '+' || \
		ft_isdigit(str[*i]))
	{
		if (str[*i] == '-')
			neg = true;
		(*i)++;
	}
	return (neg);
}

double	ft_atof(const char *str)
{
	int			whole;
	bool		neg;
	double		decimal;
	int			i;
	int			j;

	j = 1;
	decimal = 0;
	whole = ft_atoi(str);
	neg = loc_forward(str, &i);
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			decimal = decimal * 10 + str[i] - '0';
			i++;
			j *= 10;
		}
	}
	if (neg == true)
		decimal *= -1;
	return ((double)whole + (double)decimal / j);
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
