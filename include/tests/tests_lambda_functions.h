/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_lambda_functions.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:41:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 12:16:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_LAMBDA_FUNCTIONS_H
# define TESTS_LAMBDA_FUNCTIONS_H
# include <stdbool.h>
# include <stddef.h>

// lambdas - semi pure
void	do_nothing(void *data);
int		cmp_ptr_as_long(const void *data1, const void *data2);
int		cmp_raw_ptr(const void *ptrL, const void *ptrR);
void	*double_ptr(const void *data);

// array / tables
void	**creat_tb(void);
void	set_up_continuous_int_tab(int *tab, size_t size);

// --string
int		cmp_str(const void *v_data, const void *key);

// --int
bool	is_odd(const void *data);
bool	is_even(const void *data);
bool	is42(const void *data);
void	add42(void *data);
void	*add42_ret(const void *data);
int		cmp_int(const void *a, const void *b);

#endif /* TESTS_LAMBDA_FUNCTIONS_H */
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
