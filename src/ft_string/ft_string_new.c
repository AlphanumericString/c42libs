/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:00:19 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 17:50:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string	*ft_string_new(size_t capacity)
{
	t_string	*new;

	new = ft_calloc(1, sizeof(t_string));
	if (new == NULL)
		return (NULL);
	new->str = ft_calloc(capacity + 1, sizeof(char));
	if (new->str == NULL)
		return (ft_free((void **)&new), NULL);
	new->capacity = capacity;
	return (new);
}
