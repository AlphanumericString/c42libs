/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iron <iron@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:10:50 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/15 19:44:59 by iron             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*ft_shift_args(const char **args, int *index)
{
	if (*index < 0 || !args || !*args)
		return (NULL);
	return (args++[(*index)--]);
}
