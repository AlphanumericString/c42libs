/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_scope__dev.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:52:29 by antigravity       #+#    #+#             */
/*   Updated: 2026/03/28 15:52:29 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AR_SCOPE__DEV_H
# define FT_AR_SCOPE__DEV_H

# include <stddef.h>
# include "types/ft_allocator_types.h"
# include "types/ft_list_types.h"
# include "ft_defs.h"

# ifdef TEST
# define FT_AR_SCOPE_INIT_CAP 5
# else
# define FT_AR_SCOPE_INIT_CAP FT_STD_BUF_SIZE
# endif

typedef struct s_ar_scope
{
	void	**allocations;
	size_t	count;
	size_t	capacity;
}	t_ar_scope;

typedef struct s_ar_state
{
	t_dlist				*scopes;
	t_allocator_group	underlying;
}	t_ar_state;

t_ar_state	*ft_get_ar_state(void);
void		*ft_ar_alloc(size_t size);
void		*ft_ar_calloc(size_t count, size_t size);
void		ft_ar_free(void *ptr);

#endif
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
