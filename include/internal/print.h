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
