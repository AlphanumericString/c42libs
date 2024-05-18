/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:13:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/01 14:01:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strisnum(const char *str)
{
	size_t	off;

	off = 0;
	if (str[off] == '-' || str[off] == '+')
		off++;
	while (ft_isdigit(str[off]))
		off++;
	return (str[off] == 0);
}
