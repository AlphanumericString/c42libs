/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper_types.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:47:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 00:35:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_HELPER_TYPES_H
# define ARGS_HELPER_TYPES_H

# include "types/ft_args_types.h"
# include "ft_defs.h"
# include <stddef.h>

enum e_parser_type
{
	FTPA_SHORT = 0,
	FTPA_LONG
};

typedef struct s_parser_state
{
	size_t				arg_it;
	size_t				in_arg_it;
	const t_opt			*opt_list;
	int					err;
	enum e_parser_type	mode;
	const char *const	*args;
}	t_parser_state;

struct s_local_table
{
	t_data_is			checker;
	enum e_arg_types	type;
	char				*name;
};

#endif
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
