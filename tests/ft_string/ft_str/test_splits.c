/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_splits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:22:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 12:42:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <string.h>

int	tests_splits(void)
{
	const char	*str;
	char		**res;
	size_t		i;

	str = "path/to/file:another/path:yet/another/path";
	res = ft_splits(str, " /:");
	if (strcmp(res[0], "path") != 0 || strcmp(res[1], "to") != 0 || \
	strcmp(res[2], "file") != 0 || strcmp(res[3], "another") != 0 || \
	strcmp(res[4], "path") != 0 || strcmp(res[5], "yet") != 0 || \
	strcmp(res[6], "another") != 0 || strcmp(res[7], "path") != 0 || \
	res[8] != NULL)
		return (1);
	i = 0;
	while (res[i] != NULL)
		free(res[i++]);
	free(res);
	return (0);
}
