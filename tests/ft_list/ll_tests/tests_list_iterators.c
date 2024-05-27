/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:33:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:34:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	test_listend(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*last;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	last = ft_listend(list);
	if (!last)
		return (1);
	else if (last->data != data2)
		return (1);
	else if (last->next != NULL)
		return (1);
	last = ft_listend(NULL);
	if (last != NULL)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listat(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*at;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	at = ft_listat(list, 1);
	if (!at || at->data != data2 || at->next != NULL)
		return (1);
	at = ft_listat(list, 456);
	if (at != NULL)
		return (1);
	at = ft_listat(NULL, 0);
	if (at != NULL)
		return (1);
	ft_listclear(&list, free);
	return (0);
}
