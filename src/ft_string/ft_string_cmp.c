/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:20 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 18:03:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		ft_string_cmp(t_string *str, const char *cmp)
{
	size_t	i;

	i = 0;
	while (i < str->length && cmp[i])
	{
		if (str->str[i] != cmp[i])
			return (str->str[i] - cmp[i]);
		i++;
	}
	if (str->str[i] == cmp[i])
		return (0);
	return (str->str[i] - cmp[i]);
}

int		ft_string_ncmp(t_string *str, const char *cmp, size_t n)
{
	size_t	i;

	i = 0;
	while (i < str->length && cmp[i] && i < n)
	{
		if (str->str[i] != cmp[i])
			return (str->str[i] - cmp[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (str->str[i] - cmp[i]);
}

int		ft_string_cmpstr(t_string *str, t_string *cmp)
{
	size_t	i;

	i = 0;
	while (i < str->length && i < cmp->length)
	{
		if (str->str[i] != cmp->str[i])
			return (str->str[i] - cmp->str[i]);
		i++;
	}
	if (str->str[i] == cmp->str[i])
		return (0);
	return (str->str[i] - cmp->str[i]);
}

int		ft_string_ncmpstr(t_string *str, t_string *cmp, size_t n)
{
	size_t	i;

	i = 0;
	while (i < str->length && i < cmp->length && i < n)
	{
		if (str->str[i] != cmp->str[i])
			return (str->str[i] - cmp->str[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (str->str[i] - cmp->str[i]);
}