/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 07:53:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*ft_string_get(const t_string *str)
{
	return (str->str);
}

size_t	ft_string_length(const t_string *str)
{
	return (str->length);
}

size_t	ft_string_cap(const t_string *str)
{
	return (str->capacity);
}
