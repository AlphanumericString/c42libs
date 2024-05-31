/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memmove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:39 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 10:57:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

int	test_memmove(void)
{
	char		str[10];
	char		str2[10];
	const char	str3[] = "1234567\0009";

	ft_strlcpy(str, "123456789", 10);
	ft_strlcpy(str2, "123456789", 10);
	ft_memmove(str, "abc", 10);
	memmove(str2, "abc", 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	ft_memmove(str, str3, 10);
	memmove(str2, str3, 10);
	if (memcmp(str, str2, 10) != 0)
		return (2);
	ft_memmove(str, str + 2, 5);
	memmove(str2, str2 + 2, 5);
	if (memcmp(str, str2, 10) != 0)
		return (3);
	ft_memmove(str + 2, str, 5);
	memmove(str2 + 2, str2, 5);
	if (memcmp(str, str2, 10) != 0)
		return (4);
	return (0);
}
