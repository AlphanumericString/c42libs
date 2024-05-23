/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_test_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:28:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 14:26:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

int	compare_int(const void *data1, const void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

bool	is42(const void *data)
{
	return (*(int *)data == 42);
}

void	add42(void *data)
{
	*(int *)data += 42;
}

void	*add42_ret(const void *data)
{
	int	*ret;

	ret = malloc(sizeof(int));
	*ret = *(int *)data + 42;
	return (ret);
}
