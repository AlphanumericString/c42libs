/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:23:35 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 12:23:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int	test_calloc(void)
{
	char	*str;
	char	*str2;

	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));
	if (memcmp(str, str2, 10) != 0)
		return (1);
	free(str);
	free(str2);
	str = ft_calloc(0, sizeof(char));
	str2 = calloc(0, sizeof(char));
	if (memcmp(str, str2, 0) != 0)
		return (printf("got %p, expected %p\n", str, str2), 2);
	free(str);
	free(str2);
	str = ft_calloc(SIZE_MAX, SIZE_MAX);
	str2 = calloc(SIZE_MAX, SIZE_MAX);
	if (str != NULL || str2 != NULL)
		return (3);
	return (0);
}
