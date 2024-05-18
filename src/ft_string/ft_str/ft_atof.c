/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:09:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/06 08:36:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

double	ft_atof(const char *str)
{
	int			whole;
	double		decimal;
	int			i;
	int			j;

	decimal = 0;
	i = 0;
	j = 1;
	whole = ft_atoi(str);
	while (str[i] == ' ' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal = decimal * 10 + str[i] - '0';
			i++;
			j *= 10;
		}
	}
	return ((double)whole + (double)decimal / j);
}
