/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:25:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 12:25:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

int	test_substr(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = NULL;
	res = ft_substr(str, 0, 5);
	if (strcmp(res, "Hello") != 0)
		return (1);
	free(res);
	res = ft_substr(str, 6, 6);
	if (strcmp(res, "World!") != 0)
		return (2);
	free(res);
	res = ft_substr(str, 6, 100);
	if (strcmp(res, "World!") != 0)
		return (3);
	free(res);
	res = ft_substr(str, 6, 0);
	if (strcmp(res, "") != 0)
		return (4);
	free(res);
	res = ft_substr(str, 12, 0);
	if (strcmp(res, "") != 0)
		return (5);
	free(res);
	res = ft_substr(str, 12, 100);
	if (strcmp(res, "") != 0)
		return (6);
	free(res);
	return (0);
}
