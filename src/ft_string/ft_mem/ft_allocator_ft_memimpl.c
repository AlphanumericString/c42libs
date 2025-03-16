/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocator_ft_memimpl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:56:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 17:40:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_string.h"
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
void	ft_memimpl_free(void *ptr)
{
	if (SELF_ALLOC == false)
		return (free(ptr));
	ft_putstr_fd("ft_memimpl_free: not implemented\n", STDERR_FILENO);
	return ((void) NULL);
}

// null == NOT_IMPLEMENTED
void	*ft_memimpl_realloc(void *ptr, size_t size)
{
	if (SELF_ALLOC == false)
		return (realloc(ptr, size));
	ft_putstr_fd("ft_memimpl_realloc: not implemented\n", STDERR_FILENO);
	return (NULL);
}
