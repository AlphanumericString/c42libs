/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:50 by iron              #+#    #+#             */
/*   Updated: 2025/05/25 19:24:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_dl_size(const t_dlist *head)
{
	t_dlist	*it;
	size_t	i;

	i = 0;
	it = (t_dlist *)head;
	while (it)
	{
		it = it->next;
		i++;
	}
	return (i);
}

size_t	ft_dl_size_data_is(const t_dlist *head, const t_data_is function)
{
	t_dlist	*it;
	size_t	i;

	it = (t_dlist *)head;
	i = 0;
	while (it)
	{
		if (function(it->data))
			i++;
		it = it->next;
	}
	return (i);
}

size_t	ft_dl_size_cmp(const t_dlist *lst, const void *restrict data,
			const t_data_cmp cmp)
{
	t_dlist	*it;
	size_t	i;

	it = (t_dlist *)lst;
	i = 0;
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
