/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_al_memimpl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:56:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_mem.h"
#include "ft_string.h"
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

void	*ft_memimpl_malloc(size_t size)
{
	return (ft_memimpl_realloc(NULL, size));
}

void	*ft_memimpl_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (!ptr)
		return (ft_memimpl_calloc(nmemb, size));
	if (nmemb == 0 || size == 0)
		return (ft_free(ptr), NULL);
	if (nmemb >= SIZE_MAX / size)
		return (NULL);
	return (ft_memimpl_realloc(ptr, nmemb * size));
}

void	*ft_memimpl_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size == 0 || nmemb == 0)
		return (NULL);
	if (nmemb >= SIZE_MAX / size)
		return (NULL);
	res = ft_memimpl_malloc(nmemb * size);
	if (res)
		ft_bzero(res, nmemb * size);
	return (res);
}

// null == NOT_IMPLEMENTED
	// if (FT_ALLOC_SELF == false)
	// 	return (free(ptr));
void	ft_memimpl_free(void *ptr)
{
	(void)ptr;
	ft_putstr_fd("ft_memimpl_free: not implemented\n", STDERR_FILENO);
	return ((void) NULL);
}

// null == NOT_IMPLEMENTED
	// if (FT_ALLOC_SELF == false)
	// 	return (realloc(ptr, size));
void	*ft_memimpl_realloc(void *ptr, size_t size)
{
	(void)ptr;
	(void)size;
	ft_putstr_fd("ft_memimpl_realloc: not implemented\n", STDERR_FILENO);
	return (NULL);
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
