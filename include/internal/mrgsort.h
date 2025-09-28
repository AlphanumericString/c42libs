/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrgsort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:19:39 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/27 14:19:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRGSORT_H
# define MRGSORT_H

# include "ft_defs.h"

# define TMP 2
# define LEFT 0
# define RIGHT 1

typedef struct s_merge_ainfo
{
	t_data_cmp	cmp;
	size_t		n_e;
	size_t		s_e;
	void		*buf;
}	t_mainfo;

typedef struct s_merge_internal
{
	t_mainfo	anf;
	size_t		lft;
	size_t		mid;
	size_t		rgt;
}	t_minfo;

#endif // !MRGSORT_H
