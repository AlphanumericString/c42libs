/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 10:57:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

/*
	// ignore warning for memset args
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wmemset-transposed-args"
*/
int	test_memset(void)
{
	char	str[10];
	char	str2[10];

	ft_strlcpy(str, "123456789", 10);
	ft_strlcpy(str2, "123456789", 10);
	ft_memset(str, 'a', 10);
	memset(str2, 'a', 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	ft_memset(str, 'b', 0);
	if (memcmp(str, str2, 10) != 0)
		return (2);
	ft_memset(str, 'c', 5);
	memset(str2, 'c', 5);
	if (memcmp(str, str2, 10) != 0)
		return (3);
	return (0);
}
