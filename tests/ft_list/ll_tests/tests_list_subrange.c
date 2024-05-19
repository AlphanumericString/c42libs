/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_subrange.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:44:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:46:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

/*
	ft_listpush(&list, data); // (42)-> NULL
	ft_listpush(&list, data2); // (21)-> (42)-> NULL
	sub = ft_listsubrange(list, list->next); // (21)-> NULL
	sub = ft_listsubrange(list, NULL); // (21)-> (42)-> NULL
	sub = ft_listsubrange(list, (const t_list *)data2); // (21)-> (42)-> NULL
*/

int	test_listsubrange(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*sub;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	ft_listrev(&list);
	sub = ft_listsubrange(list, list->next);
	if (ft_listsize(sub) != 1 || sub->data != data2)
		return (1);
	ft_listclear(&sub, NULL);
	sub = ft_listsubrange(list, NULL);
	if (ft_listsize(sub) != 2 || sub->data != data2 || sub->next->data != data)
		return (2);
	ft_listclear(&sub, NULL);
	sub = ft_listsubrange(list, (const t_list *)data2);
	if (ft_listsize(sub) != 2 || sub->data != data2 || sub->next->data != data)
		return (3);
	ft_listclear(&sub, NULL);
	if (ft_listsubrange(NULL, NULL) != NULL)
		return (4);
	sub = ft_listsubrange(list, list);
	if (ft_listsize(sub) != 1 || sub->data != data2)
		return (5);
	return (ft_listclear(&sub, NULL), ft_listclear(&list, free), 0);
}
