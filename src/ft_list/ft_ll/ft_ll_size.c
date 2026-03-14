/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:38:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:25:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_ll_size(const t_list *lst)
{
	return (ft_ll_nsize(lst, -1));
}

size_t	ft_ll_nsize(const t_list *lst, size_t n)
{
	t_list	*it;
	size_t	i;

	i = 0;
	it = (t_list *)lst;
	while (it && i < n)
	{
		it = it->next;
		i++;
	}
	return (i);
}

size_t	ft_ll_size_data_is(const t_list *lst, t_data_is function)
{
	size_t	i;
	t_list	*it;

	i = 0;
	it = (t_list *)lst;
	while (it)
	{
		if (function(it->data))
			i++;
		it = it->next;
	}
	return (i);
}

size_t	ft_ll_size_cmp(const t_list *lst, const void *restrict data,
		const t_data_cmp cmp)
{
	size_t	i;
	t_list	*it;

	i = 0;
	it = (t_list *)lst;
	while (it)
	{
		if (cmp(it->data, data) == 0)
			i++;
		it = it->next;
	}
	return (i);
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
