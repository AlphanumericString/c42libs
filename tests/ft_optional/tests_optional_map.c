/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_optional_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:31:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:32:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"
#include "tests/optional_test.h"
#include <stdio.h>

int	test_optional_map(void)
{
	t_optional		opt;
	t_optional		ret;
	void			*(*function_list[3])(void *);

	function_list[0] = &add_4;
	function_list[1] = &add_4;
	function_list[2] = NULL;
	opt.pres = OPT_SOME;
	opt.val = (void *)42;
	ret = ft_optional_map(&opt, function_list);
	if (ret.pres != OPT_SOME)
		return (1);
	if (ret.val != (void *)42 + 8)
		return (printf("ret.val = %lld\n", (long long)ret.val), 2);
	return (0);
}
