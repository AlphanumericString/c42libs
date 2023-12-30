/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:26:28 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 18:41:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_resize(t_string *str, size_t size)
{
	char	*new;

	if (size <= str->capacity)
		return (0);
	new = ft_realloc(str->str, size);
	if (new == NULL)
		return (-1);
	ft_free((void **)&(str->str));
	str->str = new;
	str->capacity = size;
	return (0);
}
