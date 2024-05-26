/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_replace_chr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 12:46:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

int	test_str_replace_chr(void)
{
	char	*str;
	char	*res;

	str = ft_strdup("Hello World!");
	res = ft_str_replace_chr(str, 'o', 'a');
	if (strcmp(res, "Hella Warld!") != 0)
		return (1);
	free(res);
	str = ft_strdup("Hello World!");
	res = ft_str_replace_chr(str, 'o', '\0');
	if (strcmp(res, "Hell") != 0 || strcmp(res + 5, " W") != 0 || strcmp(res \
	+ 8, "rld!") != 0)
		return (4);
	free(res);
	return (0);
}
