/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:10:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/13 17:10:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "../include/contact.h"

//	line = ft_strchr(line, ' '); // skip 'add '
void	add_contact( char *line, t_list **contact_l)
{
	t_contact	con;
	t_contact	*al;

	if (!line || !contact_l)
		return ;
	line = ft_strchr(line, ' ');
	con.name = ft_strtok(line, " ");
	con.number = ft_strtok(NULL, " ");
	con.infos = ft_strtok(NULL, " ");
	if (!con.name || !con.number)
		return (ft_print_err("contact format: <name> <number> [infos]\n"),
			(void) 0);
	al = ft_calloc(sizeof(*al), 1);
	if (!al)
		return (ft_print_err("Allocation faillure\n"), (void) 0);
	if (con.name)
		al->name = ft_strdup(con.name);
	if (con.number)
		al->number = ft_strdup(con.number);
	if (con.infos)
		al->infos = ft_strdup(con.infos);
	if (ft_ll_push(contact_l, al) == NULL)
		ft_print_err("Allocation faillure\n");
}

// del_contact(rep->data);
// // TODO:
// // replace by
// // ft_ll_delete_node(contact_l, rep);
// // or
// // ft_ll_delete_node(contact_l, rep, del_contact);
void	rm_contact(char	*line, t_list **contact_l)
{
	const char	*target;
	t_list		*rep;
	t_list		*lst;

	if (!line | !contact_l)
		return ;
	target = (ft_strtok(line, " "), ft_strtok(NULL, " "));
	if (!target)
		return (ft_print_err("rm <name|phone number>"), (void) 0);
	rep = ft_ll_find(*contact_l, target, (t_data_cmp)cmp_contact_phnb);
	if (!rep)
		rep = ft_ll_find(*contact_l, target, (t_data_cmp)cmp_contact_name);
	if (!rep)
		return (ft_print("No such contact\n"), (void) 0);
	del_contact(rep->data);
	if (*contact_l == rep)
	{
		*contact_l = rep->next;
		return (ft_free(rep), (void) 0);
	}
	lst = *contact_l;
	while (lst && lst->next != rep)
		lst = lst->next;
	lst->next = rep->next;
	ft_free(rep);
}

void	disp(char *line, t_list **contact_l)
{
	t_list	*node;
	char	*target;

	if (!line | !contact_l)
		return ;
	ft_strtok(line, " ");
	target = ft_strtok(NULL, " ");
	if (!target)
	{
		ft_print_err("info <name|number>");
		return ;
	}
	node = ft_ll_find(*contact_l, target, (t_data_cmp)cmp_contact_phnb);
	if (!node)
		node = ft_ll_find(*contact_l, target, (t_data_cmp)cmp_contact_name);
	if (!node)
	{
		ft_print("No such contact\n");
		return ;
	}
	contact_printstdout(node->data);
}

void	disp_all(t_list	*contact_l)
{
	ft_ll_apply(contact_l, (t_data_apply)contact_printstdout);
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
