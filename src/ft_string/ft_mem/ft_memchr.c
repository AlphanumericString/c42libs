/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:15:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <limits.h>
#include <stdio.h>

static void	*sword_memchr(const void *s, int c, size_t n)
{
	char		*casted;
	size_t		i;
	const char	target = (char)c;

	casted = (char *)s;
	i = 0;
	while (n != i)
	{
		if (casted[i] == target)
			return (casted + i);
		i++;
	}
	return (NULL);
}

/*
** we check if the size of size_t is 8 bytes by checkning the platform
** we are on
** if yes we use the 1st function else we are on the 32 bit platform
** so use the second version
*/
/* ************************************************************************** */
/*                                                                            */
/*                           BROKEN LMAO                                      */
/*                                                                            */
/* ************************************************************************** */

/*
#ifdef __x86_64__

static void	constr_bword(size_t *target, size_t *rp_one, size_t *rp_eight,
		char c)
{
	*target = (size_t)c;
	*target |= *target << 8;
	*target |= *target << 16;
	*target |= *target << 32;
	*rp_one = 0x0101010101010101;
	*rp_eight = 0x8080808080808080;
}

#else

static void	constr_bword(size_t *target, size_t *rp_one, size_t *rp_eight,
		char c)
{
	*target = (size_t)c;
	*target |= *target << 8;
	*target |= *target << 16;
	*rp_one = 0x0101010101010101;
	*rp_eight = 0x8080808080808080;
}

#endif
*/

/*
** *casted ^ target : XOR between the target and the casted value to leave a
** segment of bits where if the target is present, the bits will be 0.
** ((*casted ^ target) - 0x0101010101010101) : XOR result - 0x0101010101010101
** remove 1 to the said bits. if target is there the result will be FF.
** ~((casted ^ target) : XOR result inverted aka 0x00 -> 0xFF and 0xFF -> 0x00
** Remember if target is present on xor segment the res is 0 so ~ will be 0xFF
**  we effectively have a mask where the target is present.
** ((*casted ^ target) - repeated_1) & ~((*casted ^ target) :
** XOR result - repeated_1 & ~XOR result
** xor result gets us to 0 where the target is
** -repeated_1 will get us to FF where the target is
** ~XOR result will get us to FF where the target is
** & between the two will get us to FF where the target is
** to filter the match we only keep the 8th bit of the result
** if the 8th bit is different from 0 we have a match in the section.
** when match send to sword_memchr to find the exact position of the target.
**
** For more infos check ft_strlen.c it is the same principle but simpler
** as we are looking directly for a 0x00.
*/

/*
static void	*bword_memchr(const void *s, int c, size_t n)
{
	size_t		*casted;
	size_t		target;
	size_t		rp_one;
	size_t		rp_eight;

	casted = (size_t *)s;
	constr_bword(&target, &rp_one, &rp_eight, c);
	while (n >= sizeof(size_t))
	{
		if ((((*casted ^ target) - rp_one) & ~(*casted ^ target)) & rp_eight)
			return (sword_memchr(casted, c, sizeof(size_t)));
		casted++;
		n -= sizeof(size_t);
	}
	if (n)
		return (sword_memchr(casted, c, n));
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*res;

	if (c < 0 || c > UCHAR_MAX || !s)
		return (NULL);
	if (n < sizeof(n))
		return (sword_memchr(s, c, n));
	else if ((size_t)s % sizeof(size_t) == 0)
		return (bword_memchr(s, c, n));
	res = sword_memchr(s, c, sizeof(size_t) - (size_t)s % sizeof(size_t));
	if (res)
		return (res);
	res = (char *)s + (sizeof(size_t) - ((size_t)s % sizeof(size_t)));
	n -= sizeof(size_t) - ((size_t)s % sizeof(size_t));
	return (bword_memchr(res, c, n));
}
*/
// if bad arg -> null
// if str less than big jump size -> sword_memchr
// else if str already aligned -> bword_memchr
// else -> sword_memchr for the first x char needed to align the str
//   if found
//		-> return result
//   put ptr to next aligned char
//   decrease n by the number x of char
//	   -> return bword_memchr

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (c < 0 || c > UCHAR_MAX || !s)
		return (NULL);
	return (sword_memchr(s, c, n));
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
