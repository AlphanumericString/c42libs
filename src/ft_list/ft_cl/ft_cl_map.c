/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:21:43 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 19:19:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"

t_clist	*ft_cl_map(const t_clist *lst, t_data_tr f, t_data_apply del)
{
	const t_clist	*it;
	t_clist			*ret;
	t_clist			*tmp;

	if (!lst || !f)
		return (NULL);
	ret = NULL;
	it = lst;
	while (1)
	{
		tmp = ft_cl_create(f(it->data));
		if (!tmp)
			return (ft_cl_delete(&ret, del), NULL);
		ft_cl_add_back(&ret, tmp);
		if (it->next == lst)
			break ;
		it = it->next;
	}
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
