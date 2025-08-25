/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_al_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:55:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"

void	*ft_malloc(size_t size)
{
	return (ft_get_allocator(NULL).ptr_alloc(size));
}

void	ft_free(void *ptr)
{
	return (ft_get_allocator(NULL).ptr_free(ptr));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	return (ft_get_allocator(NULL).ptr_calloc(nmemb, size));
}

void	*ft_realloc(void *ptr, size_t size)
{
	return (ft_get_allocator(NULL).ptr_realloc(ptr, size));
}

void	*ft_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return (ft_get_allocator(NULL).ptr_reallocarray(ptr, nmemb, size));
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
