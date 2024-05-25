/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 12:21:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	test_realloc(void)
{
	char	*str;
	char	*str2;

	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));
	str = ft_realloc(str, 20, 10);
	str2 = realloc(str2, 20);
	memset(str, 'a', 20);
	memset(str2, 'a', 20);
	if (memcmp(str, str2, 20) != 0)
		return (printf("got %s, expected %s\n", str, str2), 1);
	free(str);
	free(str2);
	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));
	str = ft_realloc(str, 2, 10);
	str2 = realloc(str2, 2);
	memset(str, 'a', 2);
	memset(str2, 'a', 2);
	if (memcmp(str, str2, 2) != 0)
		return (printf("got %s, expected %s\n", str, str2), 2);
	free(str);
	free(str2);
	return (0);
}
