/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 13:13:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

t_vector	*ft_vec_new(void)
{
	return (ft_vec_from_size(FT_VECTOR_BASE_LEN));
}

t_vector	*ft_vec_from_size(size_t n)
{
	t_vector	*ret;

	ret = ft_calloc(sizeof(t_vector), 1);
	if (!ret)
		return (ret);
	ret->datas = ft_calloc(sizeof(void *), n);
	if (!ret->datas)
		return (ft_free(ret), NULL);
	ret->cappacity = n;
	ret->count = 0;
	return (ret);
}

t_vector	*ft_vec_from_array(void **data, size_t count)
{
	t_vector	*ret;
	size_t		i;

	if (count < FT_VECTOR_BASE_LEN)
		ret = ft_vec_from_size(FT_VECTOR_BASE_LEN);
	else
		ret = ft_vec_from_size(count);
	i = 0;
	while (i < count)
	{
		ret->datas[i] = data[i];
		i++;
	}
	ret->count = i;
	return (ret);
}

t_vector	*ft_vec_convert_alloccarray(void **data, size_t count)
{
	t_vector	*ret;
	size_t		i;

	ret = ft_calloc(sizeof(t_vector), 1);
	if (!ret)
		return (ret);
	i = 0;
	ret->datas = data;
	if (!count)
	{
		while (data[i])
			i++;
		count = i + 1;
	}
	ret->count = count;
	ret->cappacity = count;
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
