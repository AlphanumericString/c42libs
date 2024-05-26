/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 11:11:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>
#include <string.h>

int	test_strjoin(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "Hello World!";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!Hello World!") != 0)
		return (1);
	free(res);
	str2 = "";
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (2);
	free(res);
	str2 = NULL;
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (3);
	free(res);
	str = "";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (4);
	free(res);
	str = NULL;
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (5);
	free(res);
	return (0);
}
