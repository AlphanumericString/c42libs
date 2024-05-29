/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isvalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:53:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 00:28:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	ft_str_isvalid(char *str, int (*is_type)(int))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_type(str[i]))
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}
