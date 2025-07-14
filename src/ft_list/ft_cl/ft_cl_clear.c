/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:33:59 by iron              #+#    #+#             */
/*   Updated: 2025/06/18 16:16:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_cl_clear(t_clist **head, t_data_apply del)
{
	size_t	ret;

	ret = ft_cl_clear_range(*head, NULL, del);
	return (ret);
}

size_t	ft_cl_clear_range(t_clist *start, const t_clist *end, t_data_apply del)
{
	const t_clist	*head = start;
	size_t			i;

	i = 0;
	while (start && start != end)
	{
		if (del)
			del(start->data);
		start->data = NULL;
		i++;
		if (end == NULL && start->next == head)
			break ;
		start = start->next;
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
