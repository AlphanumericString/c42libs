/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:27:54 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:25:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// direct call to malloc as ft_bzero is not needed
//  >> we are copying the content of ptr to new
void	*ft_realloc(void *ptr, size_t sizeNew, size_t sizeOld)
{
	void	*new;

	new = malloc(sizeNew);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, ptr, sizeOld);
	ft_free(ptr);
	return (new);
}
