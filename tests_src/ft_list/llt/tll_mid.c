/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_mid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:53:46 by bgoulard          #+#    #+#             */
/*   Updated: 2026/01/03 19:53:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "sys/cdefs.h"
#include "tests/list__ll_tests.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"

int	tll_mid(void)
{
	t_list	*lst = NULL;
	t_list	*res[4];
	const void *exp[4] = { NULL, (t_any)0xDEAD, (t_any)0xCAFE, (t_any)0xCAFE};

	res[0] = ft_ll_mid(lst);
	ft_ll_push(&lst, (t_any)0xDEAD);
	res[1] = ft_ll_mid(lst);
	ft_ll_push(&lst, (t_any)0xCAFE);
	res[2] = ft_ll_mid(lst);
	ft_ll_push(&lst, (t_any)0xBEEF);
	res[3] = ft_ll_mid(lst);
	if (res[0])
		return (1);
	if (res[1]->data != exp[1])
		return (2);
	if (res[2]->data != exp[2])
		return (3);
	if (res[3]->data != exp[2])
		return (4);
	ft_ll_clear(&lst, NULL);
	return (EXIT_SUCCESS);
}
