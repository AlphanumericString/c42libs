/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 12:48:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

int	test_str_replace(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_str_replace(str, "World", "Zod");
	if (strcmp(res, "Hello Zod!") != 0)
		return (1);
	free(res);
	res = ft_str_replace(str, "World", "");
	if (strcmp(res, "Hello !") != 0)
		return (2);
	free(res);
	res = ft_str_replace(str, "World", NULL);
	if (res != NULL)
		return (3);
	return (free(res), 0);
}
