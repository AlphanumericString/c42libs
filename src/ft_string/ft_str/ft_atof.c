/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:09:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 17:41:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_char.h"

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
	while (ft_isspace(str[i]) || str[i] == '-' || str[i] == '+' || \
		ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			decimal = decimal * 10 + str[i] - '0';
			i++;
			j *= 10;
		}
	}
	return ((double)whole + (double)decimal / j);
}
