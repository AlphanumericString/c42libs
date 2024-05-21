/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isoct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:49:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 18:55:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"

int	ft_str_isoct(char *str)
{
	if (!ft_strstart_with(str, "o") && !ft_strstart_with(str, "O"))
		return (false);
	return (ft_str_isvalid(str, ft_isoctdigit));
}
