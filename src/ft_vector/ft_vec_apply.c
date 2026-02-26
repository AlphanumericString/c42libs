/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:09:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_apply(t_vector *vec, t_data_apply func)
{
	return (ft_vec_napply(vec, -1, func));
}

void	ft_vec_napply(t_vector *vec, size_t n, t_data_apply func)
{
	size_t	i;

	if (!vec || !func || !vec->n_e || !vec->s_e || !n)
		return ;
	i = 0;
	if (n > vec->n_e)
		n = vec->n_e;
	while (i < n)
		func(vec->data + i++ *vec->s_e);
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
