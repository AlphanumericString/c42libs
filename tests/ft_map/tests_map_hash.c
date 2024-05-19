/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:21:33 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:25:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_map.h"
#include <string.h>

// we dont really test the hash function, we just test that
// it doesn't overflow our map

int	test_map_hash(void)
{
	size_t	ret;

	ret = ft_hash_djb2("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	ret = ft_hash_sdbm("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	ret = ft_hash_fnv1a("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	ret = ft_hash_dummy("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	return (0);
}
