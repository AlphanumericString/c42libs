/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isfloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:45:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_string.h"
#include "ft_char.h"

// no value check like isint due to the fact that it's a floating point
bool	ft_str_isfloat(const char *str)
{
	size_t	i;
	bool	dot;

	if (!str)
		return (false);
	i = 0;
	dot = false;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && !dot)
			dot = true;
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (i == 0 || (i == 1 && (str[0] == '.' || str[0] == '-')) || \
	(i == 2 && str[0] == '-' && str[1] == '.') || \
	i > 20)
		return (false);
	return (true);
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
