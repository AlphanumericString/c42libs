/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_sizers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:43:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:46:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

int	test_listsize(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	size_ret[0] = ft_listsize(NULL);
	size_ret[1] = ft_listsize(list->next);
	size_ret[2] = ft_listsize(list);
	if (size_ret[0] != 0)
		return (1);
	if (size_ret[1] != 1)
		return (1);
	if (size_ret[2] != 2)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listsize_match(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	size_ret[0] = ft_listsize_match(NULL, is42);
	size_ret[1] = ft_listsize_match(list, is42);
	size_ret[2] = ft_listsize_match(list->next, is42);
	if (size_ret[0] != 0)
		return (1);
	if (size_ret[1] != 1)
		return (1);
	if (size_ret[2] != 0)
		return (1);
	ft_listclear(&list, free);
	return (0);
}
