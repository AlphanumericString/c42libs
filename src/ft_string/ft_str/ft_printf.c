/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:18:09 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/01 23:18:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "ft_stris.h"
#include "internal/print.h"

#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <wchar.h>

int	ft_sprintf(char *s, const char *fmt, ...);
int	ft_snprintf(char *s, size_t n, const char *fmt, ...);
int	ft_vprintf(const char *fmt, va_list list);
int	ft_vsprintf(char *s, const char *fmt, va_list list);
int	ft_vsnprintf(char *s, size_t n, const char *fmt, va_list list);
int	ft_printf(const char *fmt, ...);

int	ft_sprintf(char *s, const char *fmt, ...) {
	(void)s; (void)fmt;
	return (-1);}
int	ft_snprintf(char *s, size_t n, const char *fmt, ...){
	(void)n;
	(void)s; (void)fmt;
	return (-1);};
int	ft_vprintf(const char *fmt, va_list list){
	(void)list; (void)fmt;
	return (-1);};
int	ft_vsprintf(char *s, const char *fmt, va_list list){
	(void)s; (void)fmt;
	(void)list;
	return (-1);};


typedef struct {
	char	*buf;
	size_t	buf_offset;
	size_t	max;
	const char	*fmt;
	size_t	fmt_offset;
} t_ft_printf;

enum e_len {
	FT_PR_BASE_LEN = 0,
	FT_PR_CHAR_LEN, // hh
	FT_PR_SHORT, // h
	FT_PR_LONG_LONG, // ll q
	FT_PR_LONG, // l    - char->wint_t || wchar_t, FLOAT_* = ignore
	FT_PR_LONG_DOUBLE, // L      - also works for ints ?
	FT_PR_STD_MAXINT, // j
	FT_PR_STD_SIZE, // z Z
	FT_PR_STD_PTRDIFF // t
};

// NOTE: value spcified for masks
enum e_flags {
	F_ZERO	=	1 << 0,
	F_MINUS =	1 << 1,
	F_SPACE =	1 << 2,
	F_HTAGS	=	1 << 3,
	F_PLUS	=	1 << 4,
	F_QUOTE	=	1 << 5,
};

// TODO: handlers
// handler format:
// bool // -> success / fail
// handler_name (
//	t_ft_printf *buffer_infos,
//	t_ft_printf_arg *arg_info,
//	va_list			arg_list
// );
enum e_type_specifier {
	FT_PR_INTEGER = 0,
	FT_PR_UNSIGNED,
	FT_PR_STRING,
	FT_PR_CHARACTER,
	FT_PR_ADRESS,
	FT_PR_INFO_NB,
	FT_PR_U_OCTAL,
	FT_PR_ERRNO_VALUE,
	FT_PR_U_HEXADECIMAL_MIN = 8,
	FT_PR_U_HEXADECIMAL_MAJ = 9,
	FT_PR_DOUBLE_MIN = 10,
	FT_PR_DOUBLE_MAJ = 11,
	FT_PR_DOUBLE_EXP_MIN = 12,
	FT_PR_DOUBLE_EXP_MAJ = 13,
	FT_PR_DOUBLE_SMART_MIN = 14,
	FT_PR_DOUBLE_SMART_MAJ = 15,
	FT_PR_DOUBLE_HEX_MIN = 16,
	FT_PR_DOUBLE_HEX_MAJ = 17,
	FT_PR_MODULO,
};

typedef struct {
	const char *c;
	enum e_len l;
} t_len_conv;

typedef struct {
	char c;
	enum e_flags f;
} t_flag_conv;

typedef struct {
	char c;
	enum e_type_specifier t;
} t_ts_conv;

// INFO: 'const char *' -> start of w || p
typedef struct {
	int				flags;
	enum e_len		len_mod;
	const char		*width; // -width => flag '-' and width (even with *)
	const char		*prec; // -prec => prec considered ommied
	char			conv;
	size_t			a_len;
} t_ft_printf_arg;

static bool	is_good(t_ft_printf inf, t_ft_printf_arg *arg)
{
	const t_len_conv len_mod[] = { {"hh", FT_PR_CHAR_LEN}, {"h", FT_PR_SHORT},
	{"ll", FT_PR_LONG_LONG}, {"l", FT_PR_LONG}, {"q", FT_PR_LONG_LONG},
	{"L", FT_PR_LONG}, {"j", FT_PR_STD_MAXINT}, {"z", FT_PR_STD_SIZE},
	{"Z", FT_PR_STD_SIZE}, {"t", FT_PR_STD_PTRDIFF}, {NULL, 0}};
	const t_ts_conv	types[] = {
	{'d', FT_PR_INTEGER}, {'i', FT_PR_INTEGER}, {'o', FT_PR_U_OCTAL},
	{'u', FT_PR_UNSIGNED}, {'x', FT_PR_U_HEXADECIMAL_MIN},
	{'X', FT_PR_U_HEXADECIMAL_MAJ}, {'e', FT_PR_DOUBLE_EXP_MIN},
	{'E', FT_PR_DOUBLE_EXP_MAJ}, {'f', FT_PR_DOUBLE_MIN},
	{'F', FT_PR_DOUBLE_MAJ}, {'g', FT_PR_DOUBLE_SMART_MIN},
	{'G', FT_PR_DOUBLE_SMART_MAJ}, {'a', FT_PR_DOUBLE_HEX_MIN},
	{'A', FT_PR_DOUBLE_HEX_MAJ}, {'c', FT_PR_CHARACTER},
	{'s', FT_PR_STRING}, {'p', FT_PR_ADRESS}, {'n', FT_PR_INFO_NB},
	{'%', FT_PR_MODULO}, {'m', FT_PR_ERRNO_VALUE}, {0, 0}};
	const char			*flags_all = "#0-+ '";
	const t_flag_conv	flags_conv[] = {
	{'0', F_ZERO}, {'-', F_MINUS}, {' ', F_SPACE}, {'#', F_HTAGS},
	{'+', F_PLUS}, {'\'', F_QUOTE}, {0, 0}
	};
	size_t		i;


	arg->a_len = 1;

	// flag(s)
	i = 0;
	while (inf.fmt[inf.fmt_offset + arg->a_len] && flags_conv[i].c
		&& ft_strchr(flags_all, inf.fmt[inf.fmt_offset + arg->a_len]) != 0)
	{
		while (flags_conv[i].c
			&& flags_conv[i].c != inf.fmt[inf.fmt_offset + arg->a_len])
			i++;
		arg->flags |= flags_conv[i].f;
		(arg->a_len)++;
	}

	// width
	if (inf.fmt[inf.fmt_offset + arg->a_len] == '*'
		|| ft_isdigit(inf.fmt[inf.fmt_offset + arg->a_len]))
		arg->width = &(inf.fmt[inf.fmt_offset + (arg->a_len)++]);
	while (ft_isdigit(inf.fmt[inf.fmt_offset + arg->a_len]))
		(arg->a_len)++;

	// prec
	if (inf.fmt[inf.fmt_offset + arg->a_len] == '.')
	{
		arg->prec = &(inf.fmt[inf.fmt_offset + (arg->a_len)++]);
		while (ft_isdigit(inf.fmt[inf.fmt_offset + arg->a_len]))
			arg->a_len++;
	}

	// len_mod
	i = 0;
	while (len_mod[i].c)
	{
		if (!ft_strncmp(len_mod[i].c, &inf.fmt[inf.fmt_offset + arg->a_len],
			ft_strlen(len_mod[i].c)))
			break ;
		i++;
	}
	if (len_mod[i].c) {
		arg->a_len += ft_strlen(len_mod[i].c);
		arg->len_mod = len_mod[i].l;
	}

	// type_conv
	i = 0;
	while (types[i].c)
	{
		if (types[i].c == inf.fmt[inf.fmt_offset + arg->a_len])
			break;
		i++;
	}
	arg->a_len++;
	arg->conv = types[i].c;
	return (arg->conv != 0);
}

static void set_wp(int *w, int *p, t_ft_printf_arg *arg, va_list lst)
{
	if (arg->width && arg->width[0] == '*')
		*w = va_arg(lst, int);
	else if (arg->width)
		*w = ft_atoi(arg->width);
	*p = -1;
	if (arg->prec && arg->prec[0] == '*')
		*p = va_arg(lst, int);
	else if (arg->prec)
		*p = ft_atoi(arg->prec + 1);
}

// TODO: WCHAR strings
// static int	process_wstring(t_ft_printf *inf, t_ft_printf_arg *arg, va_list list);

static int	process_string(t_ft_printf *inf, t_ft_printf_arg *arg, va_list list)
{
	const char	*dflt = "(null)";
	const char	*s;
	int			wdth;
	int			prec;
	int			append_needed;

	set_wp(&wdth, &prec, arg, list);
	s = va_arg(list, char *);
	if (!s && arg->prec && prec >= (int)ft_strlen(dflt))
		s = dflt;
	else if (!s)
		s = "";
	append_needed = 0;
	if ((arg->flags & F_MINUS) != F_MINUS) {
		if (arg->width && (int)ft_strnlen(s, (size_t)prec) < wdth) {
			while (append_needed++ + (int)ft_strnlen(s, prec) < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}

	int i = 0;
	while (s[i] && (!arg->prec || (arg->prec && i < prec)))
		inf->buf[inf->buf_offset++] = s[i++];

	if ((arg->flags & F_MINUS) == F_MINUS) {
		if (arg->width && (int)ft_strnlen(s, (size_t)prec) < wdth) {
			while (append_needed++ + (int)ft_strnlen(s, prec) < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}
	if (append_needed)
		append_needed--;
	return (append_needed + i - 1);
}

static int	process_errno(t_ft_printf *inf, t_ft_printf_arg *arg, va_list list)
{
	const char	*s;
	int			wdth;
	int			prec;
	int			append_needed;

	set_wp(&wdth, &prec, arg, list);
	s = ft_strerror(errno);
	if (!s)
		s = "";
	append_needed = 0;
	if ((arg->flags & F_MINUS) != F_MINUS) {
		if (arg->width && (int)ft_strnlen(s, (size_t)prec) < wdth) {
			while (append_needed++ + (int)ft_strnlen(s, prec) < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}

	int i = 0;
	while (s[i] && (!arg->prec || (arg->prec && i < prec)))
		inf->buf[inf->buf_offset++] = s[i++];

	if ((arg->flags & F_MINUS) == F_MINUS) {
		if (arg->width && (int)ft_strnlen(s, (size_t)prec) < wdth) {
			while (append_needed++ + (int)ft_strnlen(s, prec) < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}
	if (append_needed)
		append_needed--;
	return (append_needed + i);
}

// TODO: wcrtomb
static int	sub_process_wchar(t_ft_printf *inf, t_ft_printf_arg *arg, va_list lst)
{
	wchar_t		wchr;
	int			wdth;
	int			prec;
	int			append_needed;

	set_wp(&wdth, &prec, arg, lst);
	append_needed = 0;
	if ((arg->flags & F_MINUS) != F_MINUS) {
		if (arg->width && 1 < wdth) {
			while (append_needed++ + 1 < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}

	wchr = va_arg(lst, wchar_t);
	ft_memcpy(inf->buf + inf->buf_offset, &wchr, sizeof(wchar_t));
	inf->buf_offset += sizeof(wchar_t);

	if ((arg->flags & F_MINUS) == F_MINUS) {
		if (arg->width && 1 < wdth) {
			while (append_needed++ + 1 < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}
	if (append_needed)
		append_needed--;
	return (append_needed + sizeof(wchar_t));
}

static int	sub_process_char(t_ft_printf *inf, t_ft_printf_arg *arg, va_list lst)
{
	int			wdth;
	int			prec;
	int			append_needed;

	set_wp(&wdth, &prec, arg, lst);
	append_needed = 0;
	if ((arg->flags & F_MINUS) != F_MINUS) {
		if (arg->width && 1 < wdth) {
			while (append_needed++ + 1 < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}

	inf->buf[inf->buf_offset++] = (char)va_arg(lst, int);

	if ((arg->flags & F_MINUS) == F_MINUS) {
		if (arg->width && 1 < wdth) {
			while (append_needed++ + 1 < wdth)
				inf->buf[inf->buf_offset++] = ' ';
		}
	}
	if (append_needed)
		append_needed--;
	return (append_needed + 1);
}

static int process_char(t_ft_printf *inf, t_ft_printf_arg *arg, va_list list)
{
	if (arg->len_mod == FT_PR_LONG)
		return (sub_process_wchar(inf, arg, list));
	return (sub_process_char(inf, arg, list));
}

static int process_mod(t_ft_printf *inf, t_ft_printf_arg *arg, va_list list)
{
	int			wdth;
	int			prec;

	set_wp(&wdth, &prec, arg, list);
	inf->buf[inf->buf_offset++] = '%';
	return (1);
}

static int process_nb(t_ft_printf *inf, t_ft_printf_arg *arg, va_list list)
{
	void *p;

	p = va_arg(list, void *);
	switch (arg->len_mod) {
	case FT_PR_CHAR_LEN: // hh
		*((char *)p) = inf->buf_offset;
		break;
	case FT_PR_SHORT: // h
		*((short *)p) = inf->buf_offset;
		break;
	case FT_PR_LONG_LONG: // ll q
		*((long long *)p) = inf->buf_offset;
		break;
	case FT_PR_LONG: // l    - char->wint_t || wchar_t, FLOAT_* = ignore
		*((long *)p) = inf->buf_offset;
		break;
	case FT_PR_STD_MAXINT: // j
		*((intmax_t *)p) = inf->buf_offset;
		break;
	case FT_PR_STD_SIZE: // z Z
		*((size_t *)p) = inf->buf_offset;
		break;
	case FT_PR_STD_PTRDIFF: // t
		*((ptrdiff_t *)p) = inf->buf_offset;
		break;
	default:
		*((int *)p) = inf->buf_offset;
		break;
	}

	return (0);
}

static int	treat_arg(t_ft_printf *inf, va_list list)
{
	t_ft_printf_arg	arg;

	arg = (t_ft_printf_arg){0};
	if (is_good(*inf, &arg) == false)
	{
		inf->buf[(inf->buf_offset)++] = inf->fmt[(inf->fmt_offset)++];
		return (1);
	}
	inf->fmt_offset += arg.a_len;
	/*
	 * call associated hdnler
	*/
	switch (arg.conv)
	{
	case 's':
		return (process_string(inf, &arg, list));
	case 'm':
		return (process_errno(inf, &arg, list));
	case 'c':
		return (process_char(inf, &arg, list));
	case '%':
		return (process_mod(inf, &arg, list));
	case 'n':
		return (process_nb(inf, &arg, list));
	default:
		inf->buf[(inf->buf_offset)++] = inf->fmt[(inf->fmt_offset)++];
		return (1);
	}
}

int	ft_vsnprintf(char *buf, size_t max, const char *fmt, va_list list)
{
	t_ft_printf infos;
	size_t			len;

	if (!buf || !fmt)
		return (-1);
	infos.buf = buf;
	infos.buf_offset = 0;
	infos.max = max;
	infos.fmt = fmt;
	infos.fmt_offset = 0;
	len = 0;
	while (len < (infos.max - 1) && infos.fmt[infos.fmt_offset])
	{
		if (infos.fmt[infos.fmt_offset] == '%')
			len += treat_arg(&infos, list);
		else
		{
			len++;
			infos.buf[infos.buf_offset++] = infos.fmt[infos.fmt_offset++];
		}
	}
	infos.buf[infos.buf_offset] = 0;
	// printf("infos.fmt_offset: '%zu'\n", infos.fmt_offset);
	// printf("infos.fmt: '%s'\n", infos.fmt);
	// printf("infos.buf_offset: '%zu'\n", infos.buf_offset);
	// printf("infos.buf: '%s'\n", infos.buf);
	return ((int)len);
}

int	ft_printf(const char *fmt, ...)
{
	char	buff[FT_STD_BUF_SIZE + 1];
	char	*s;
	va_list	list;
	size_t	n;

	if (!ft_strchr(fmt, FT__PRINTF_META_CHAR))
		return (ft_putstr_fd(fmt, STDOUT_FILENO));
	ft_bzero(buff, FT_STD_BUF_SIZE);
	s = NULL;
	va_start(list, fmt);
	n = ft_vsnprintf(buff, FT_STD_BUF_SIZE, fmt, list);
	va_end(list);
	if (n <= FT_STD_BUF_SIZE)
		return (write(STDOUT_FILENO, buff, n));
	s = ft_malloc(sizeof(char) * (n + 1));
	if (!s)
		return (-1);
	va_start(list, fmt);
	n = ft_vsprintf(s, fmt, list);
	va_end(list);
	if (n < 0)
		return (ft_free(s), n);
	n = write(STDOUT_FILENO, s, n);
	return (ft_free(s), n);
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
