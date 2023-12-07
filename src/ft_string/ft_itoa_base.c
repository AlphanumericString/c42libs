/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:11 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/05 10:22:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	loc_getlen(long long nbr, int blen)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		nbr_len++;
	}
	nbr_len += ft_llogof(nbr, blen);
	return (nbr_len);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char		*ret;
	size_t		off;
	long long	srcnbr;
	const int	nbrlen = loc_getlen((long long)nbr, ft_strlen(base));

	srcnbr = (long long)nbr;
	ret = ft_calloc(sizeof(char), (nbrlen + 1));
	if (!ret)
		return (NULL);
	if (srcnbr <= 0)
	{
		if (srcnbr == 0)
			ret[0] = '0';
		else
			ret[0] = '-';
		srcnbr *= -1;
	}
	off = 0;
	while (srcnbr)
	{
		ret[nbrlen - ++off] = base[srcnbr % 10];
		srcnbr /= 10;
	}
	return (ret);
}
