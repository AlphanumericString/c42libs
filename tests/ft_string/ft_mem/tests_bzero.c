/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:24:17 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 10:54:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>
#include <strings.h>

int	test_bzero(void)
{
	char	str[10];
	char	str2[10];

	ft_strlcpy(str, "123456789", 10);
	ft_strlcpy(str2, "123456789", 10);
	ft_bzero(str, 10);
	bzero(str2, 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	return (0);
}
