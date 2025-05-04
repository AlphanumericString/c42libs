/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:17:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/05 17:36:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_cl_add_back(t_clist **head, t_clist *const added)
{
	if (!head || !added)
		return ;
	if (!*head)
	{
		*head = added;
		added->prev = added;
		added->next = *head;
		return ;
	}
	added->prev = (*head)->prev;
	added->next = *head;
	(*head)->prev->next = added;
	(*head)->prev = added;
	return ;
}

void	ft_cl_add_front(t_clist **head, t_clist *const added)
{
	if (!head || !added)
		return ;
	if (!*head)
	{
		added->prev = added;
		added->next = added;
		return (*head = added, (void)0);
	}
	added->next = *head;
	added->prev = (*head)->prev;
	(*head)->prev->next = added;
	(*head)->prev = added;
	return (*head = added, (void)0);
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
