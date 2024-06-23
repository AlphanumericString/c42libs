/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:15:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/13 16:47:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*casted;
	size_t		i;
	const char	target = (char)c;

	casted = (char *)s;
	i = 0;
	while (n != i)
	{
		if (casted[i++] == target)
			return (casted + i - 1);
	}
	return (NULL);
}
