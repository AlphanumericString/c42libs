/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:56:17 by bgoulard          #+#    #+#             */
/*   Updated: 2023/11/12 09:56:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (s1[index] && ((unsigned char *)s1)[index] \
	== ((unsigned char *)s2)[index] && index != n - 1)
		index++;
	return (((unsigned char *)s1)[index] - ((unsigned char *)s2)[index]);
}
