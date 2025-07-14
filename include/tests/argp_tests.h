/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argp_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:03:08 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 19:03:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGP_TESTS_H
# define ARGP_TESTS_H

# include <stdbool.h>

typedef struct s_usr
{
	int				nbr;
	int				i_nbr;
	long			l_nbr;
	unsigned int	hex;
	unsigned int	hex2;
	unsigned int	oct;
	const char		*str;
	const char		*fil;
	bool			boo;
	float			flo;
	double			dou;
	const char		*aln;
	void			*custom;
}	t_usr;

// bindings / setters to call on opptions
// /file1
int	set_digit(void *user_struct, const char *arg);
int	set_int(void *user_struct, const char *arg);
int	set_long(void *user_struct, const char *arg);
int	set_hex2(void *user_struct, const char *arg);
int	set_hex(void *user_struct, const char *arg);
// /file2
int	set_oct(void *user_struct, const char *arg);

#endif /* ARGP_TESTS_H */
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
