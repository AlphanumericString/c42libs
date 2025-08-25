/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:08:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:34:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

#include "ft_string.h"
#include "types/ft_string_types.h"

int	ft_putnbr_fd(int nb, int fd)
{
	char	res[13];
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (fd < 0 || fd > MAX_FD)
		return (-1);
	ft_bzero(res, sizeof(res) / sizeof(res[0]));
	if (nb == INT_MIN || nb == INT_MAX)
		return (write(fd, (char *)((long)"-2147483648" *(nb == INT_MIN))
			+ ((long)"2147483647" *(nb == INT_MAX)), 10 + (nb == INT_MIN)));
	if (nb < 0)
		sign = -1;
	if (nb == 0)
		res[i++] = '0';
	while (nb != 0)
	{
		res[i++] = (nb % 10) * sign + '0';
		nb /= 10;
	}
	if (sign == -1)
		res[i++] = '-';
	return (ft_strrev(res), write(fd, res, i));
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
