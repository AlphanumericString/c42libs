/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:27 by iron              #+#    #+#             */
/*   Updated: 2025/03/31 01:40:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_at(const t_dlist *head, size_t index)
{
	size_t	i;
	t_dlist	*it;

	it = (t_dlist *)head;
	i = 0;
	while (i != index && it)
	{
		i++;
		it = it->next;
	}
	return (it);
}

t_dlist	*ft_dl_end(const t_dlist *head)
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it->next)
		it = it->next;
	return (it);
}

t_dlist	*ft_dl_begin(const t_dlist *head)
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it->prev)
		it = it->prev;
	return (it);
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
