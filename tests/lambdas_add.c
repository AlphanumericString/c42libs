/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambdas_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:42:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/26 16:12:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests_lambda_functions.h"

void	add42(void *data)
{
	int	*ptr;

	ptr = (int *)data;
	*ptr += 42;
}

void	*add42_ret(const void *data)
{
	int	*ret;

	ret = ft_malloc(sizeof(int));
	if (!ret)
		return (NULL);
	*ret = *(int *)data;
	*ret += 42;
	return ((void *)ret);
}
