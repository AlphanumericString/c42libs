/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:07:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/13 16:07:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "ft_list.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "../include/contact.h"

static void	process(char *line, t_list **contact_l, bool *state)
{
	if (!ft_strcmp(line, "quit") || !ft_strcmp(line, "exit"))
		return (*state = false, (void) 0);
	if (ft_strstart_with(line, "add "))
		return (add_contact(line, contact_l));
	else if (ft_strstart_with(line, "remove ") || ft_strstart_with(line, "rm "))
		return (rm_contact(line, contact_l));
	else if (ft_strstart_with(line, "info "))
		return (disp(line, contact_l));
	else if (!ft_strcmp(line, "help"))
	{
		ft_print("Commands:\n");
		ft_print("  add <name> <number> [infos] : add a contact\n");
		ft_print("  rm <name|number>            : remove a contact\n");
		ft_print("  info <name|number>          : display a contact\n");
		ft_print("  disp                        : display all contacts\n");
		ft_print("  help                        : display this help message\n");
		ft_print("  exit | quit                 : exit the program\n");
		return ;
	}
	else if (!ft_strcmp(line, "disp"))
		return (disp_all(*contact_l));
	ft_print_err("could not recognize : '%s'\n", line);
	return ;
}

int main(void)
{
	bool	running;
	char	*line;
	t_list	*contact_list;

	running = true;
	contact_list = NULL;
	while (running)
	{
		ft_print("$> ");
		line = ft_gnl(STDIN_FILENO);
		if (!line)
			break ;
		ft_strrpl_chr(line, '\n', 0);
		process(line, &contact_list, &running);
		ft_free(line);
	}
	printf("contact_list : %zu\n", ft_ll_size(contact_list));
	disp_all(contact_list);
	ft_ll_delete(&contact_list, (t_data_apply)del_contact);
	return EXIT_SUCCESS;
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
