/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:39:42 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 17:39:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_arr.h"

void	*ft_acollect(t_const_arr *arr, void *start_val, t_data_tr_w f)
{
	return (ft_ancollect(arr, -1, start_val, f));
}

void	*ft_ancollect(t_const_arr *arr, size_t n, void *start_val,
		t_data_tr_w f)
{
	size_t	i;
	void	*ret;

	i = 0;
	if (!f || !arr)
		return (NULL);
	while (i < n && arr[i])
		ret = f(arr[i++], start_val);
	return (ret);
}

void	*ft_ancollect_r(t_const_arr *ar, size_t n, void *start_val,
		t_data_tr_w f)
{
	void	*ret;
	size_t	i;

	i = 0;
	if (!f || !ar)
		return (NULL);
	i = ft_anlen((t_const_arr)ar, n);
	if (i != 0 && !ar[i])
		i--;
	while (i)
		ret = f(ar[i--], start_val);
	return (ret);
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
