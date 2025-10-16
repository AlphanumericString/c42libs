/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_extract_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:39:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/09 20:39:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__dl_tests.h"
#include <stdio.h>

int	tdl_extract_max(void)
{
	const char	*arr[] = {"a", "b", "c", "d", "e", "f", NULL};
	t_dlist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_dl_push(&list, (void *)arr[i++]);
	if (ft_dl_extract_max(list, (t_any)ft_strcmp) != (void *)arr[i - 1])
		return (1);
	if (ft_dl_extract_max(NULL, (t_any)ft_strcmp) != NULL
		|| ft_dl_extract_max(list, NULL) != NULL)
		return (2);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
}

int	tdl_extract_max_node(void)
{
	const char	*arr[] = {"a", "b", "c", "d", "e", "f", NULL};
	t_dlist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_dl_push_back(&list, (void *)arr[i++]);
	if (ft_dl_extract_max_node(list, (t_any)ft_strcmp)->data
		!= (void *)arr[i - 1])
		return (1);
	if (ft_dl_extract_max_node(NULL, (t_any)ft_strcmp) != NULL
		|| ft_dl_extract_max_node(list, NULL) != NULL)
		return (2);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
}
