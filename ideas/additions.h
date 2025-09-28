/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:53:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/27 14:53:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// additions to ft_list.h
//
//
#ifndef ADDITIONS_H
# define ADDITIONS_H

# ifndef FT_NOVEC_UROLL
#  include "types/ft_vector_types.h"
# endif

# define FTLIST_UBLOCK_SIZE	32

/// @brief Structure to make any other structure inot a liked list
/// @param next the next node
/// @param prev the prev node
/// @note i - intrusive, d - doubly linked
/// @note the user is expected to have a field of this type in his structure
/// to make it into a list
typedef struct s_idlist
{
	struct s_idlist	*next;
	struct s_idlist	*prev;
}	t_idlist;

# ifndef FT_NOVEC_UROLL

/// @brief	structure to have a "unrolled" linked list
/// @param	vec_data the table of data grouped by block of FTLIST_UBLOCK_SIZE
/// @param	lst the lst field turns the t_ulist into a linked list by using
/// the keyword offsetof
typedef struct s_ulist
{
	t_vector	vec_data;
	t_idlist	lst;
}	t_ulist;

# else

/// @brief	structure to have a "unrolled" linked list
/// @param	data the table of data grouped by block of FTLIST_UBLOCK_SIZE
/// @param	count number of element present in data (internal)
/// @param	next the next node
/// @param	prev the prev node
typedef struct s_ulist
{
	void			*data[FTLIST_UBLOCK_SIZE];
	size_t			count;
	t_idlist		lst;
}	t_ulist;

# endif

# define FTLIST_SKIP_SIZE	32

typedef struct s_skip_list
{
	void				*data;
	int					level;
	struct s_skip_list	*nexts[FTLIST_SKIP_SIZE];
}	t_skip_list;

#endif /* ADDITIONS_H */
