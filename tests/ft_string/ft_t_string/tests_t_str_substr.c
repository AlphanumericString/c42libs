/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_substr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 17:36:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_struct.h"
#include <string.h>

int	test_string_substr(void)
{
	t_string	*str;
	t_string	*sub;

	str = ft_string_from("Hello World");
	sub = ft_string_substr(str, 0, 6);
	if (sub == NULL)
		return (1);
	if (strcmp(sub->str, "Hello") != 0)
		return (2);
	if (sub->length != 5)
		return (3);
	if (sub->capacity < 5)
		return (4);
	ft_string_destroy(&str);
	ft_string_destroy(&sub);
	return (0);
}

