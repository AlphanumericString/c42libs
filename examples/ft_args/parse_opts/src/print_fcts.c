/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:02:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:07:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/example.h"
#include "ft_string.h"

#include <unistd.h>
#include <stddef.h>

void	printf_reaminer_args(const char *const *av, size_t offset)
{
	unsigned int	i;

	i = (unsigned int)offset;
	while (av[i])
	{
		ft_print_fd(STDOUT_FILENO, "Extra argument %u: %s\n", i, av[i]);
		i++;
	}
}

int	print_long_version(void *usr)
{
	(void)usr;
	ft_print_fd(STDOUT_FILENO, "loooog version called\n");
	return (0);
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
