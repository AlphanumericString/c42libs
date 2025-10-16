/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:36:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/10 14:36:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__dl_tests.h"

static void	push_arr(t_dlist **list, size_t *i, const char **arr)
{
	*list = NULL;
	*i = 0;
	while (arr[*i])
		ft_dl_push(list, (t_any)arr[(*i)++]);
}

// [1-2] => errors
// [3] => ASC
// [4] => DES
// [5] =>
int	tdl_sort(void)
{
	const char	*arr[] = {"non", "ordered", "array", "for", "test", NULL};
	t_dlist		*lst;
	size_t		i;

	lst = NULL;
	if (ft_dl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != NULL
		|| ft_dl_sort(NULL, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != NULL)
		return (1);
	push_arr(&lst, &i, arr);
	if (ft_dl_sort(&lst, NULL, FT_SORT_ORD_ASC) != NULL
		|| ft_dl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_UNO) != lst)
		return (2);
	if ((ft_dl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) == NULL
			|| ft_dl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != true)
		|| (ft_dl_sort(&lst, (t_any)ft_strcmp, 0) == NULL
			|| ft_dl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != true))
		return (3);
	if (ft_dl_sort(&lst, (t_any)ft_strcmp, FT_SORT_ORD_DES) == NULL
		|| ft_dl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_DES) != true)
		return (4);
	return (ft_dl_delete(&lst, NULL), EXIT_SUCCESS);
}
