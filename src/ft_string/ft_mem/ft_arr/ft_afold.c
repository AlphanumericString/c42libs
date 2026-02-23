/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:08:49 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 18:08:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	ft_afold(t_arr *ar, t_data_tr_w f) {
	if (!ar || !f)
		 return ;
	return (ft_anfold(ar, ft_alen((t_const_arr)ar), f));
}

void	ft_anfold(t_arr *ar, size_t n, t_data_tr_w f)
{
	size_t	i;

	if (!ar || n < 2 || !f)
		return ;
	i = 1;
	while (ar[i] && i < n) {
		f(ar[i - 1], ar[i]);
		i += 2;
	}
}

void	ft_anfold_r(t_arr *ar, size_t n, t_data_tr_w f)
{
	size_t	i;

	if (!ar || n < 2 || !f)
		return ;
	i = ft_anlen((t_const_arr)ar, n);
	if (i != 0 && !ar[i])
		i--;
	while (i > 1)
	{
		f(ar[i - 1], ar[i]);
		i -= 2;
	}
}

void	ft_anfold_mltp(t_arr *ar, size_t n, t_data_tr_w f, size_t mlt)
{
	if (!ar || n < 2 || !f || !mlt)
		return ;
	while (mlt && n > 1)
	{
		ft_anfold(ar, n, f);
		n = (n / 2) + (n % 2);
		mlt--;
	}
}

void	ft_anfold_r_mltp(t_arr *ar, size_t n, t_data_tr_w f, size_t mlt)
{
	if (!ar || n < 2 || !f || !mlt)
		return ;
	while (mlt && n > 1)
	{
		ft_anfold_r(ar, n, f);
		n = (n / 2) + (n % 2);
		mlt--;
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
