/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:22:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/03 11:22:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include <stddef.h>

void	ft_arev(t_iconst_arr array)
{
	size_t		len;
	size_t		it;
	const void	*p;

	it = 0;
	if (!array || !array[0] || !array[1])
		return ;
	len = ft_alen(array) - 1;
	while (it <= len / 2)
	{
		p = array[it];
		array[it] = array[len];
		array[len] = p;
		it++;
		len--;
	}
}

void	ft_anrev(t_iconst_arr array, size_t n)
{
	size_t		len;
	size_t		it;
	const void	*p;

	it = 0;
	if (n < 2 || !array || !array[0] || !array[1])
		return ;
	len = ft_alen(array) - 1;
	if (n > len)
		n = len + 1;
	while (it < n / 2)
	{
		p = array[it];
		array[it] = array[n - it - 1];
		array[n - it - 1] = p;
		it++;
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
