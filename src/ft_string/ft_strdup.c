/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:33:24 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/05 10:27:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strdup(const char *strsrc)
{
	const size_t	len = ft_strlen(strsrc);
	size_t			index;
	char			*ret;

	ret = NULL;
	ret = ft_calloc(sizeof(char), (len + 1));
	if (!ret)
		return (ret);
	index = 0;
	while (strsrc[index])
	{
		ret[index] = strsrc[index];
		index++;
	}
	return (ret);
}
