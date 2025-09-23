/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:37:44 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 03:36:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_TYPES_H
# define FT_LIST_TYPES_H

# include "ft_defs.h"
# define FTLIST_SUCCESS EXIT_SUCCESS
# define FTLIST_FAILURE EXIT_FAILURE

/// @brief Structure representing a node in a simple linked list
/// @param data The data of the node
/// @param next The next node
/// @note this is the naive first apporoach of a linked list
typedef struct s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

/// @brief Structure representing a node in a doubly linked list
/// @param data The data of the node
/// @param next The next node
/// @param prev The previous node
/// @note this is the naive first apporoach of a doubly linked list
typedef struct s_dl_list
{
	struct s_dl_list	*next;
	struct s_dl_list	*prev;
	void				*data;
}						t_dlist;

/// @brief Structure for circular lists, done with a rename to explicit
///		functions working on circular lists
typedef t_dlist			t_clist;

/// @brief Type of function to apply on a doubly linked list node
typedef void			(*t_cnode_apply)(t_clist *);

/// @brief Type of function to apply on a doubly linked list node
typedef void			(*t_dnode_apply)(t_dlist *);

/// @brief Type of function to apply on a simply linked list node
typedef void			(*t_lnode_apply)(t_list *);

#endif /* FT_LIST_TYPES_H */
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
