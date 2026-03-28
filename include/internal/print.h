/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:44:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/10 23:53:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>

# define FT__PRINTF_CONVERTION_SPECIFIERS	"cspdiuoxX%fFeEm"
# define FT__PRINTF_META_CHAR				'%'

enum e_processor_type
{
	STRING_PROCESSOR = 1,//%s
	CHAR_PROCESSOR,//%c
	INT_PROCESSOR,//%d + %i
	UINT_PROCESSOR, //%u
	HEX_PROCESSOR, //%x
	HEX_UPPER_PROCESSOR, //%X
	OCTAL_PROCESSOR, //%o
	PTR_PROCESSOR, //%p
	META_PROCESSOR, //%%
	FLOAT_PROCESSOR, //%f
	FLOAT_UPPER_PROCESSOR, //%F
	EXP_PROCESSOR, //%e
	EXP_UPPER_PROCESSOR, //%E
	ERRNO_PROCESSOR, //%m
	ERROR = 0,
};

typedef struct s_processor
{
	enum e_processor_type	type;
	char					link;
	int						(*func)(va_list args, int fd);
}	t_processor;

int	meta_processor(va_list args, int fd);
int	errno_processor(va_list args, int fd);
int	string_processor(va_list args, int fd);
int	uint_processor(va_list args, int fd);
int	int_processor(va_list args, int fd);
int	flt_processor(va_list args, int fd);
int	flt_upper_processor(va_list args, int fd);
int	exp_processor(va_list args, int fd);
int	exp_upper_processor(va_list args, int fd);
int	char_processor(va_list args, int fd);
int	hex_processor(va_list args, int fd);
int	hex_upper_processor(va_list args, int fd);
int	octal_processor(va_list args, int fd);
int	ptr_processor(va_list args, int fd);

#endif // PRINT_H
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
