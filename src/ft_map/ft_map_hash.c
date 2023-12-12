/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:07:04 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 19:15:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

// Default hash function for ft_map
size_t	ft_map_hash(void *key, size_t capacity, size_t size)
{
	unsigned char	*str;
	size_t			hash;

	hash = 0;
	str = (unsigned char *)key;
	while (size--)
		hash = (hash << 5) + *str++;
	return (hash % capacity);
}
