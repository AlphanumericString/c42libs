/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 12:22:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

int	test_memchr(void)
{
	char	str[10];

	ft_strlcat(str, "1234567\0009", 10);
	if (ft_memchr(str, '1', 10) != memchr(str, '1', 10))
		return (1);
	if (ft_memchr(str, '5', 10) != memchr(str, '5', 10))
		return (2);
	if (ft_memchr(str, '9', 10) != memchr(str, '9', 10))
		return (3);
	if (ft_memchr(str, '0', 10) != memchr(str, '0', 10))
		return (4);
	if (ft_memchr(str, 'a', 10) != memchr(str, 'a', 10))
		return (5);
	if (ft_memchr(str, 'A', 10) != memchr(str, 'A', 10))
		return (6);
	if (ft_memchr(str, '\0', 10) != memchr(str, '\0', 10))
		return (7);
	return (0);
}
