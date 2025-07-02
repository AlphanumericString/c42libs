/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:59:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/02 23:59:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

int	ft_print(const char *str, ...)
{
	va_list	lst;
	int		ret;

	va_start(lst, str);
	ret = ft_vaprint_fd(STDOUT_FILENO, str, lst);
	va_end(lst);
	return (ret);
}

int	ft_print_err(const char *str, ...)
{
	va_list	lst;
	int		ret;

	va_start(lst, str);
	ret = ft_vaprint_fd(STDERR_FILENO, str, lst);
	va_end(lst);
	return (ret);
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
