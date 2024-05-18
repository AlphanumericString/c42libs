/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:14:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 19:18:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memfmap(void *src, size_t size, void *(*f)(void *))
{
	void	**dst;
	size_t	i;

	dst = malloc(size);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = f(src + i);
		i++;
	}
	return (dst);
}
