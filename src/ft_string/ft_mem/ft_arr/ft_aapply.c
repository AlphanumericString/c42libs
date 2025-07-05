/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aapply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:47:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 16:02:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include <stddef.h>
#include <stdio.h>

void	ft_aapply(t_oconst_arr array, t_data_apply f)
{
	size_t	i;

	i = 0;
	if (!array || !f)
		return ;
	while (array[i])
		f(array[i++]);
}

void	ft_anapply(t_oconst_arr array, size_t n, t_data_apply f)
{
	size_t	i;

	i = 0;
	if (!array || !f || !n)
		return ;
	while (i < n && array[i])
		f(array[i++]);
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
