/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 03:49:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 16:45:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#ifdef DEBUG

int	ft_string_putdbg(t_string *str, int fd)
{
	char	tmp[100];

	memset(tmp, 0, 100);
	if (fd < 0 || str == NULL || (str->str == NULL && str->length != 0))
		return (-1);
	strncat(tmp, str->str, str->length);
	return (printf("str->str: '%s'\n", tmp) + printf("str->length: %zu\n",
			str->length) + printf("str->capacity: %zu\n", str->capacity));
}

#else

int	ft_string_putdbg(t_string *str, int fd)
{
	(void)str;
	(void)fd;
	return (EXIT_SUCCESS);
}

#endif

int	ft_string_put(t_string *str, int fd)
{
	int	ret;

	if (fd < 0 || str == NULL || (str->str == NULL && str->length != 0))
		return (-1);
	ret = write(fd, str->str, str->length);
	return (ret);
}
