/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:21:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:22:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/ll_tests.h"
#include <stdlib.h>

int	test_listclear(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	ft_listclear(&list, NULL);
	list = ft_listcreate(data);
	ft_listclear(&list, free);
	ft_listclear(NULL, NULL);
	return (0);
}
