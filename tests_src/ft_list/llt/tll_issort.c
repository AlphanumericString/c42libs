/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_issort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 06:09:10 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/09 06:09:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__ll_tests.h"
#include "types/ft_list_types.h"
#include <stdio.h>

static void	push_arr(t_list **list, size_t *i, const char **arr)
{
	*list = NULL;
	*i = 0;
	while (arr[*i])
		ft_ll_push(list, (t_any)arr[(*i)++]);
}

static bool	cmp_all(const t_list *lst, bool exp[3])
{
	if (ft_ll_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != exp[0]
		|| (ft_ll_issort(lst, (t_any)ft_strcmp, 0)
			!= ft_ll_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC))
		|| ft_ll_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_DES) != exp[1]
		|| ft_ll_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_UNO) != exp[2])
		return (true);
	return (false);
}

int	tll_issort(void)
{
	const char	*arr[] = {"hello", "world", "this", "is", "Zod", NULL};
	const char	*arr2[] = {"str0", "str1", "str2", "str3", "str4", NULL};
	const char	*arr3[] = {"str4", "str3", "str2", "str1", "str0", NULL};
	t_list		*lst;
	size_t		i;

	push_arr(&lst, &i, arr);
	if (cmp_all(lst, (bool [3]){false, false, true}) != false)
		return (2);
	(ft_ll_delete(&lst, NULL), push_arr(&lst, &i, arr2));
	if (cmp_all(lst, (bool [3]){false, true, true}) != false)
		return (3);
	(ft_ll_delete(&lst, NULL), push_arr(&lst, &i, arr3));
	if (cmp_all(lst, (bool [3]){true, false, true}) != false)
		return (4);
	if (ft_ll_issort(lst, NULL, FT_SORT_ORD_ASC) != false
		|| ft_ll_issort(lst, NULL, FT_SORT_ORD_DES) != false
		|| ft_ll_issort(lst, NULL, FT_SORT_ORD_UNO) != true)
		return (5);
	ft_ll_delete(&lst, NULL);
	if (cmp_all(lst, (bool [3]){true, true, true}) != false)
		return (6);
	return (ft_ll_delete(&lst, NULL), EXIT_SUCCESS);
}
