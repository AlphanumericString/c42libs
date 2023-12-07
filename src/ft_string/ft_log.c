/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:09:57 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 16:45:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ullogof(unsigned long long nbr, int base)
{
	int	pow;

	pow = 0;
	while (nbr)
	{
		nbr /= base;
		pow++;
	}
	return (pow);
}

int	ft_llogof(long long nbr, int base)
{
	int	pow;

	if (nbr <= 0)
		return (-1);
	pow = 0;
	while (nbr)
	{
		nbr /= base;
		pow++;
	}
	return (pow);
}

int	ft_logof(int nbr, int base)
{
	int	pow;

	if (nbr <= 0)
		return (-1);
	pow = 0;
	while (nbr)
	{
		nbr /= base;
		pow++;
	}
	return (pow);
}

int	ft_log(int nbr)
{
	return (ft_logof(nbr, 10));
}
