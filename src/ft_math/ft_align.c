/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:51:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/09/30 10:09:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_align_multiple_2(size_t size, size_t pow_2)
{
	return ((size + pow_2 - 1) & ~(pow_2 - 1));
}

size_t	ft_align_2(size_t size)
{
	return ((size + 2 - 1) & ~(2 - 1));
}

size_t	ft_align(size_t size, size_t alignment)
{
	if (alignment < 2)
		return (size);
	if (size % alignment == 0)
		return (size);
	return (size + (alignment - size % alignment));
}
