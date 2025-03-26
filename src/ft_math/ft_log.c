/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:09:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_ullogof(unsigned long long nbr, int base)
{
	const unsigned long long	bul = (unsigned long long)base;
	int							pow;

	pow = -1;
	while (nbr)
	{
		nbr /= bul;
		pow++;
	}
	return (pow);
}

int	ft_llogof(long long nbr, int base)
{
	if (nbr <= 0)
		return (-1);
	return (ft_ullogof((unsigned long long)nbr, base));
}

int	ft_logof(int nbr, int base)
{
	if (nbr <= 0)
		return (-1);
	return (ft_llogof((long long)nbr, base));
}

int	ft_log(int nbr)
{
	return (ft_logof(nbr, 10));
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
