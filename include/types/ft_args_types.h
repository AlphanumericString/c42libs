/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 00:35:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_TYPES_H
# define FT_ARGS_TYPES_H

# include <stdint.h>

// << by the amount of bits used by the previous enum in the union
// max : 2^2 [harg -> has_arg]
enum e_has_arg
{
	FT_AH_NO = 0 << 0, // default
	FT_AH_YES = 1 << 0,
	FT_AH_MAYBE = 2 << 0,
	FT_AH_MASK = 3 << 0, // mask for has_arg
};

// max : 2^2
enum e_separator
{
	FT_AS_NEXT_ARG = 0 << 2,
	FT_AS_EQSIGN = 1 << 2,
	FT_AS_MASK = 3 << 2, // mask for separator
};

// << by the amount of bits used by the previous enum in the union
// max : 2^5 -> 32
enum e_arg_types
{
	FT_AT_UNSPECIFIED = 0 << 4, // default : keep first defined (used in code)
	FT_AT_INT = 1 << 4,
	FT_AT_LONG = 2 << 4,
	FT_AT_NBR = 3 << 4,
	FT_AT_HEX = 4 << 4,
	FT_AT_OCT = 5 << 4,
	FT_AT_STR = 6 << 4,
	FT_AT_FNAME = 7 << 4,
	FT_AT_BOOL = 8 << 4,
	FT_AT_FLOAT = 9 << 4,
	FT_AT_DOUBLE = 10 << 4, // same checks - idk diff in range w flts
	FT_AT_ALPHANUM = 11 << 4,
	FT_AT_CUSTOM = 12 << 4, // keep last defined (used in code)
	FT_AT_MASK = 31 << 4, // mask for arg types
};

# ifndef FT_ARG_PARSER_OD
#  define FT_ARG_PARSER_OD 1
# endif

// [OD -> options descriptions]
# if defined(FT_ARG_PARSER_OD) && FT_ARG_PARSER_OD != 0

typedef struct s_opt
{
	const char	*long_name;
	char		short_name;
	const void	*func;
	uint16_t	type;
	const char	*desc;
}				t_opt;

# else

typedef struct s_opt
{
	const char	*long_name;
	char		short_name;
	const void	*func;
	uint16_t	type;
}				t_opt;

# endif /* FT_ARG_PARSER_OD */

#endif /* FT_ARGS_TYPES_H */
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
