/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:36:39 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 18:54:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args_types.h"
#include "ft_args.h"
#include "ft_char.h"
#include "ft_string.h"
#include <stdlib.h>

// 0 success, !0 failure

int	checker_arg(t_opt_type type, char *arg)
{
	if (!arg)
		return (type & OPT_ARG);
	if (type & OPT_INT)
		return (!ft_str_isint(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_STRING)
		return (EXIT_SUCCESS);
	else if ((type & ARG_MASK_ATYPE) == OPT_BOOL)
		return (!ft_str_isbool(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_FLOAT)
		return (!ft_str_isfloat(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_LONG)
		return (!ft_str_islong(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_DOUBLE)
		return (!ft_str_isdouble(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_ALPHANUM)
		return (!ft_str_isvalid(arg, ft_isalnum));
	else if ((type & ARG_MASK_ATYPE) == OPT_HEX)
		return (!ft_str_ishex(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_OCT)
		return (!ft_str_isoct(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_OTHER
		&& ft_arg_get_custom_checker())
		return (!ft_arg_get_custom_checker()(arg));
	return (EXIT_SUCCESS);
}
