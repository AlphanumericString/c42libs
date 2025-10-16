/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_extract_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:39:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/10 14:46:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__cl_tests.h"
#include <stdio.h>

int	tcl_extract_max(void)
{
	const char	*arr[] = {"a", "b", "c", "d", "e", "f", NULL};
	t_clist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_cl_push(&list, (void *)arr[i++]);
	if (ft_cl_extract_max(list, list->prev, (t_any)ft_strcmp)
		!= (t_any)arr[i - 1])
		return (1);
	if (ft_cl_extract_max(NULL, list->prev, (t_any)ft_strcmp) != NULL
		|| ft_cl_extract_max(list, list->prev, NULL) != NULL)
		return (2);
	return (ft_cl_delete(&list, NULL), EXIT_SUCCESS);
}

int	tcl_extract_max_node(void)
{
	const char	*arr[] = {"a", "b", "c", "d", "e", "f", NULL};
	t_clist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_cl_push_back(&list, (t_any)arr[i++]);
	if (ft_cl_extract_max_node(list, NULL, (t_any)ft_strcmp)->data
		!= (t_any)arr[i - 1])
		return (1);
	if (ft_cl_extract_max_node(NULL, NULL, (t_any)ft_strcmp) != NULL
		|| ft_cl_extract_max_node(list, list->prev, NULL) != NULL)
		return (2);
	return (ft_cl_delete(&list, NULL), EXIT_SUCCESS);
}
