/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_opt_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:01:33 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 03:59:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "types/ft_args_types.h"
#include "internal/args_helper.h"
#include <stdlib.h>
#include <stddef.h>

static const t_opt	**singleton_opt_list(void)
{
	static const t_opt	*singleton_opt_list = NULL;

	return (&singleton_opt_list);
}

int	ft_set_opt_list(t_opt *opt_list_c)
{
	size_t	ol_it;
	t_opt	*opt_list;

	if (!opt_list_c)
		return (EXIT_FAILURE);
	ol_it = 0;
	opt_list = (t_opt *)opt_list_c;
	while (opt_list[ol_it].func)
	{
		if (opt_list[ol_it].type != 0
			&& (opt_list[ol_it].type & FT_AH_MASK) == FT_AH_NO)
		{
			opt_list[ol_it].type = (opt_list[ol_it].type | FT_AH_YES);
		}
		ol_it++;
	}
	*singleton_opt_list() = opt_list;
	return (EXIT_SUCCESS);
}

const t_opt	*ft_get_opt_list(void)
{
	return (*singleton_opt_list());
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
