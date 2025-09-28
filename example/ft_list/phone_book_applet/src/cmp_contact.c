/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_contact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:24:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/13 17:24:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.h"
#include "ft_mem.h"
#include "ft_string.h"

int	cmp_contact_phnb(const t_contact *cntact, const char *phnb)
{
	if (!cntact | !phnb)
		return (-1);
	return (ft_strcmp(cntact->number, phnb));
}

int	cmp_contact_name(const t_contact *cntact, const char *name)
{
	if (!cntact | !name)
		return (-1);
	return (ft_strcmp(cntact->name, name));
}

void	del_contact(t_contact *con)
{
	if (!con)
		return ;
	ft_free(con->name);
	ft_free(con->number);
	ft_free(con->infos);
	ft_free(con);
}

void	contact_printstdout(const t_contact *con)
{
	if (!con)
		return (ft_print("\n"), (void) 0);
	if (con->name)
	{
		ft_print(con->name);
		if (con->number || con->infos)
			ft_print("\t");
	}
	if (con->number)
	{
		ft_print(con->number);
		if (con->infos)
			ft_print("\t");
	}
	if (con->infos)
		ft_print(con->infos);
	ft_print("\n");
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
