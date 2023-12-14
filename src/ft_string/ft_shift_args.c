/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:10:50 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/14 17:19:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*ft_shift_args(const char **args, int index)
{
	if (index < 0 || !args || !*args)
		return (NULL);
	return (args++[index--]);
}
