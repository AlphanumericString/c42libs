/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:28:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 22:59:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_string.h"

void	*ft_calloc(size_t nmemb, size_t weight)
{
	void	*ret;
	size_t	tot;

	if (nmemb == 0 || weight == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / weight)
		return (NULL);
	tot = nmemb * weight;
	ret = malloc(tot);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, tot));
}
