/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/16 10:59:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_char.h"



long long	ft_atoll_base(const char *str, const char *base)
{
	const size_t	base_len = ft_strlen(base);
	long long		nb;
	int				i;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!ft_base_valid(base))
		return (0);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && ft_strchr(base, str[i]))
		nb = nb * base_len + ft_strchr(base, str[i++]) - base;
	return (nb * sign);
}

long	ft_atol_base(const char *str, const char *base)
{
	return ((long)ft_atoll_base(str, base));
}

int	ft_atoi_base(const char *str, const char *base)
{
	return ((int)ft_atoll_base(str, base));
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
