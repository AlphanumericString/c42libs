/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 12:22:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

int	test_memcmp(void)
{
	const char	str[] = "1234567\0009";
	const char	str2[] = "1234567\0009";
	const char	str3[] = "1234567\000a";
	const char	str4[] = "1234567\0009";

	if (ft_memcmp(str, str2, 10) != memcmp(str, str2, 10))
		return (1);
	if (ft_memcmp(str, str3, 10) != memcmp(str, str3, 10))
	{
		if (!(ft_memcmp(str, str3, 10) < 0 && memcmp(str, str3, 10) < 0))
			return (2);
	}
	if (ft_memcmp(str, str2, 0) != memcmp(str, str2, 0))
		return (3);
	if (ft_memcmp(str, str4, 10) != memcmp(str, str4, 10))
		return (4);
	return (0);
}
