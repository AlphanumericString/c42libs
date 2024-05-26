/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:10 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 11:12:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strcmp(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;

	str = "none";
	str2 = "some";
	str3 = "nonethensome";
	str4 = "nonethensome";
	str5 = "!\0a";
	str6 = "!\0b";
	if (ft_strcmp(str, str2) >= 0)
		return (1);
	if (ft_strcmp(str, str3) >= 0)
		return (2);
	if (ft_strcmp(str3, str4) != 0)
		return (3);
	if (ft_strcmp(str5, str6) != 0)
		return (4);
	return (0);
}
