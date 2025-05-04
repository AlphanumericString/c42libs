/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:09:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/10 13:23:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset_types.h"
#include "ft_bitset.h"
#include "ft_string.h"
#include <stdio.h>

static void print_bitset8(t_bitset8 b8, int fd, const char *fmt[3])
{
	const bool	bit[8] = {b8.b0, b8.b1, b8.b2, b8.b3, b8.b4, b8.b5, b8.b6, \
	b8.b7};
	size_t		i;

	i = 0;
	if (fd < 0 || !fmt || !fmt[0] || !fmt[1])
		return ;
	while (i < 8)
	{
		if (bit[i])
			ft_putstr_fd(fmt[0], fd);
		else
			ft_putstr_fd(fmt[1], fd);
		if (i != 7 && fmt[2])
			ft_putstr_fd(fmt[2], fd);
		i++;
	}
}

// true | false print w 8 bits per lines
void	ft_bs_print(t_bitset *bitset, int fd)
{
	const char	*fmt[3] = {"true", "false", ", "};
	size_t		i;

	if (fd < 0 || !bitset)
		return ;
	i = 0;
	while (i < bitset->_capacity)
	{
		print_bitset8(bitset->bits[i], fd, fmt);
		ft_putstr_fd("\n", fd);
		i++;
	}
}

// 1 | 0 print w 8 bits per lines
void	ft_bs_print_binary(t_bitset *bitset, int fd)
{
	const char	*fmt[3] = {"1", "0", NULL};
	size_t		i;

	if (fd < 0 || !bitset)
		return ;
	i = 0;
	while (i < bitset->_capacity)
	{
		print_bitset8(bitset->bits[i], fd, fmt);
		ft_putstr_fd("\n", fd);
		i++;
	}
}

// 0x__ print w space between until last with endl
void	ft_bs_print_hex(t_bitset *bitset, int fd)
{
	const char	*prepend = "0x";
	const char	*base = "0123456789abcdef";
	char		str[3];
	size_t		i;

	if (fd < 0 || !bitset)
		return ;
	i = 0;
	ft_bzero(str, 3);
	while (i < bitset->_capacity)
	{
		str[1] = base[bitset->bits[i].raw % 16];
		str[0] = base[bitset->bits[i].raw / 16];
		ft_putstr_fd(prepend, fd);
		ft_putstr_fd(str, fd);
		if (i != bitset->_capacity - 1)
			ft_putstr_fd(" ", fd);
		i++;
	}
	ft_putstr_fd("\n", fd);
}

// ___ print w space between until last with endl
void	ft_bs_print_decimal(t_bitset *bitset, int fd)
{
	char	str[4];
	size_t	i;

	if (fd < 0 || !bitset)
		return ;
	i = 0;
	ft_bzero(str, 4);
	while (i < bitset->_capacity)
	{
		str[0] = (bitset->bits[i].raw / 100) + '0';
		str[1] = ((bitset->bits[i].raw / 10) % 10) + '0';
		str[2] = (bitset->bits[i].raw % 10) + '0';
		ft_putstr_fd(str, fd);
		if (i != bitset->_capacity - 1)
			ft_putstr_fd(", ", fd);
		i++;
	}
	ft_putstr_fd("\n", fd);
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
