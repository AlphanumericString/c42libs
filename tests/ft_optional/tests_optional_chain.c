/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_optional_chain.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:28:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:29:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"
#include "tests/optional_test.h"
#include <stdio.h>

int	test_optional_chain(void)
{
	t_optional		opt;
	bool			ret;
	void			*(*function_list[3])(void *);

	function_list[0] = &add_4;
	function_list[1] = &add_4;
	function_list[2] = NULL;
	opt.pres = OPT_SOME;
	opt.val = (void *)42;
	ret = ft_optional_chain(&opt, function_list);
	if (ret != true)
		return (1);
	if (opt.pres != OPT_SOME)
		return (2);
	if (opt.val != (void *)42 + 8)
		return (printf("opt.val = %lld\n", (long long)opt.val), 3);
	return (0);
}
