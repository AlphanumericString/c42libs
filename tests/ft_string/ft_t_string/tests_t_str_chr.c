/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 21:13:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_chr(void)
{
	t_string	*str;
	const char	*src;
	char		c;

	src = "Hello world this is zod!";
	c = 0;
	str = ft_string_from(src);
	while (c < 127)
		if (ft_string_chr(str, c) == ft_strchr(src, c))
			return (c + 1);
	return (0);
}
