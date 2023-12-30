/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:18 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 18:12:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_string_trim(t_string *str)
{
	char	*new_str;

	new_str = ft_strtrim(str->str, " \t\n");
	ft_string_set(str, new_str);
	free(new_str);
}

void	ft_string_trim_chr(t_string *str, char c)
{
	char	*new_str;

	new_str = ft_strtrim(str->str, &c);
	ft_string_set(str, new_str);
	free(new_str);
}

void	ft_string_trimstr(t_string *str, char *to_trim)
{
	char	*new_str;

	new_str = ft_strtrim(str->str, to_trim);
	ft_string_set(str, new_str);
	free(new_str);
}
