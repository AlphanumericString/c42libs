/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:05:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/23 19:43:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

long long	ft_atoll(const char *str)
{
	return (ft_atoll_base(str, "0123456789"));
}

long	ft_atol(const char *str)
{
	return ((long)ft_atoll_base(str, "0123456789"));
}

int	ft_atoi(const char *str)
{
	return (ft_atoi_base(str, "0123456789"));
}
