/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str__str_tests.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:28:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:46:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR__STR_TESTS_H
# define STR__STR_TESTS_H

int	str_tests(int d);

int	test_atod(void);
int	test_atoi_base(void);
int	test_atoi(void);
int	test_atol(void);
int	test_atoll(void);
int	test_atol_base(void);
int	test_itoa_base(void);
int	test_itoa(void);
int	test_utoa(void);

int	test_gnl(void);
int	test_shift_args(void);

int	test_perror(void);
int	test_putendl(void);
int	test_putnbr(void);
int	test_putstr(void);

int	test_split(void);
int	tests_splits(void);
int	test_strappend_c(void);
int	test_strchr(void);
int	test_strclen(void);
int	test_strcmp(void);
int	test_strcnb(void);
int	test_strcspn(void);
int	test_strdup(void);
int	test_strend_with(void);
int	test_striteri(void);
int	test_strjoin(void);
int	test_strlcat(void);
int	test_strlcpy(void);
int	test_strlen(void);
int	test_strmapi(void);
int	test_strncmp(void);
int	test_strndup(void);
int	test_strnstr(void);
int	test_strrchr(void);
int	test_str_replace_chr(void);
int	test_str_replace(void);
int	test_strrev(void);
int	test_strspn(void);
int	test_strstart_with(void);
int	test_strtok(void);
int	test_strtrim(void);
int	test_substr(void);

int	test_str_isalnum(void);
int	test_str_isalpha(void);
int	test_str_isbool(void);
int	test_str_isdigit(void);
int	test_str_isdouble(void);
int	test_str_isfloat(void);
int	test_str_ishex(void);
int	test_str_isint(void);
int	test_str_islong(void);
int	test_str_isnum(void);
int	test_str_isoct(void);
int	test_str_isvalid(void);

#endif /* STR__STR_TESTS_H */
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
