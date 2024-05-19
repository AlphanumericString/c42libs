/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listcopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:24:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:25:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/lists_test_utils.h"
#include "tests/ll_tests.h"
#include <stdlib.h>

int	test_listcopy_node(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	copy = ft_listcopy_node(list);
	if (!copy)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next != list->next)
		return (1);
	free(data);
	free(list);
	free(copy);
	return (0);
}

int	test_listcopy_list(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;
	int		*data2;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	copy = ft_listcopy_list(list);
	if (!copy)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (!copy->next)
		return (1);
	else if (copy->next->data != list->next->data)
		return (1);
	else if (copy->next->next != NULL)
		return (1);
	ft_listclear(&list, free);
	ft_listclear(&copy, NULL);
	return (0);
}
