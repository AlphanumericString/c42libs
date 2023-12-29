/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:48:50 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 14:38:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static size_t	loc_get_nbwords(const char *str, const char *delim)
{
	size_t	ret;
	size_t	i;
	size_t	inword;

	ret = 0;
	i = 0;
	inword = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strchr(delim, str[i++]))
		{
			if (inword == 1)
				ret++;
			inword = 0;
		}
		else
			inword = 1;
	}
	if (inword == 1)
		ret++;
	return (ret);
}

char	**ft_splits(const char *str, char *delim)
{
	char	*str_cpy;
	char	*s;
	size_t	offset_words;
	char	**words;

	words = ft_calloc(sizeof(char *), (loc_get_nbwords(str, delim) + 1));
	if (!words)
		return (NULL);
	offset_words = 0;
	str_cpy = ft_strdup(str);
	s = ft_strtok(str_cpy, delim);
	while (s)
	{
		words[offset_words++] = ft_strdup(s);
		s = ft_strtok(NULL, delim);
	}
	free(str_cpy);
	return (words);
}
