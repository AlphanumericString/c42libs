/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 12:22:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

int	test_memcpy(void)
{
	char		str[10];
	char		str2[10];
	const char	str3[] = "1234567\0009";

	ft_strlcat(str, "123456789", 10);
	ft_strlcat(str2, "123456789", 10);
	ft_memcpy(str, "abc", 10);
	memcpy(str2, "abc", 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	ft_memcpy(str, str3, 10);
	memcpy(str2, str3, 10);
	if (memcmp(str, str2, 10) != 0)
		return (2);
	return (0);
}
