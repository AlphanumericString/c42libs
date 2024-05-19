/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listcreate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:23:08 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:23:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/ll_tests.h"
#include <stdlib.h>

int	test_listcreate(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	if (!list)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next != NULL)
		return (1);
	free(data);
	free(list);
	return (0);
}
