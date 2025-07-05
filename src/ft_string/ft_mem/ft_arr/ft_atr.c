/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:18:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 16:13:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include <stddef.h>

void	ft_atr(t_arr arr, t_data_tr_i tr)
{
	ssize_t	i;

	if (!tr || !arr)
		return ;
	i = -1;
	while (arr[++i])
		arr[i] = tr(arr[i]);
}

void	ft_antr(t_arr arr, size_t n, t_data_tr_i tr)
{
	size_t	i;

	if (!tr || !arr || !n)
		return ;
	i = 0;
	while (arr[i] && i < n)
	{
		arr[i] = tr(arr[i]);
		i++;
	}
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
