/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_islong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:50:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 17:49:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "ft_string.h"
#include "ft_char.h"

int	ft_str_islong(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if ((i == 19 && ft_strcmp(str, "9223372036854775807") > 0) || (i == 20
			&& ft_strcmp(str, "-9223372036854775808") > 0) || i > 20)
		return (false);
	return (true);
}
