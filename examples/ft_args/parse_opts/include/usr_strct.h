/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usr_strct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:57:08 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/12 17:17:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USR_STRCT_H
# define USR_STRCT_H
# include "ft_defs.h"

typedef struct s_usr_struct	t_usr_struct;
struct s_usr_struct
{
	int		int_val;
	long	long_val;
	float	float_val;
	double	double_val;
	bool	bool_val;
	char	*string_val;
};

#endif
