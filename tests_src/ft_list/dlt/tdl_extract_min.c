/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_extract_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:07:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/10 14:07:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__dl_tests.h"
#include <stdio.h>

int	tdl_extract_min(void)
{
	const char	*arr[] = {"looong", "a", "longer", "long", "tiny", NULL};
	t_dlist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_dl_push(&list, (void *)arr[i++]);
	if (ft_dl_extract_min(list, (t_any)ft_strcmp) != (void *)arr[1])
		return (1);
	if (ft_dl_extract_min(NULL, (t_any)ft_strcmp) != NULL
		|| ft_dl_extract_min(list, NULL) != NULL)
		return (2);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
}

int	tdl_extract_min_node(void)
{
	const char	*arr[] = {"looong", "a", "longer", "long", "tiny", NULL};
	t_dlist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_dl_push(&list, (void *)arr[i++]);
	if (ft_dl_extract_min_node(list, (t_any)ft_strcmp)->data != (void *)arr[1])
		return (1);
	if (ft_dl_extract_min_node(NULL, (t_any)ft_strcmp) != NULL
		|| ft_dl_extract_min_node(list, NULL) != NULL)
		return (2);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
}
