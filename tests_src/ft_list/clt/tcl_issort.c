/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_issort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:20:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/10 14:47:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests//list__cl_tests.h"
#include <stdio.h>

static void	push_arr(t_clist **list, size_t *i, const char **arr)
{
	*list = NULL;
	*i = 0;
	while (arr[*i])
		ft_cl_push(list, (t_any)arr[(*i)++]);
}

static bool	cmp_all(const t_clist *lst, bool exp[3])
{
	if (ft_cl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC) != exp[0]
		|| (ft_cl_issort(lst, (t_any)ft_strcmp, 0)
			!= ft_cl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_ASC))
		|| ft_cl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_DES) != exp[1]
		|| ft_cl_issort(lst, (t_any)ft_strcmp, FT_SORT_ORD_UNO) != exp[2])
		return (true);
	return (false);
}

int	tcl_issort(void)
{
	const char	*arr[] = {"non", "ordered", "array", "for", "test", NULL};
	t_clist		*lst_fwd;
	t_clist		*lst_bwd;
	size_t		i;

	(push_arr(&lst_fwd, &i, arr), push_arr(&lst_bwd, &i, arr));
	if (cmp_all(lst_fwd, (bool [3]){false, false, true}) != false)
		return (1);
	ft_cl_sort(&lst_fwd, (t_data_cmp)ft_strcmp, FT_SORT_ORD_ASC);
	ft_cl_sort(&lst_bwd, (t_data_cmp)ft_strcmp, FT_SORT_ORD_DES);
	if (cmp_all(lst_fwd, (bool [3]){true, false, true}) != false
		|| cmp_all(lst_bwd, (bool [3]){false, true, true}) != false)
		return (2);
	if (ft_cl_issort(lst_fwd, NULL, FT_SORT_ORD_ASC) != false
		|| ft_cl_issort(lst_bwd, NULL, FT_SORT_ORD_ASC) != false)
		return (3);
	(ft_cl_delete(&lst_fwd, NULL), ft_cl_delete(&lst_bwd, NULL));
	ft_cl_push(&lst_fwd, (t_any)"single");
	if (cmp_all(lst_bwd, (bool [3]){true, true, true}) != false
		|| cmp_all(lst_fwd, (bool [3]){true, true, true}) != false)
		return (4);
	return (ft_cl_delete(&lst_fwd, NULL), EXIT_SUCCESS);
}
