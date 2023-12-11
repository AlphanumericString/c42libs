/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:37:44 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 15:17:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_STRUCT_H
# define FT_LIST_STRUCT_H

# include <stdbool.h>
# define FTLIST_SUCCESS 0
# define FTLIST_FAILURE 1

typedef struct s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

typedef struct s_dl_list
{
	struct s_dl_list	*next;
	struct s_dl_list	*prev;
	void				*data;
}						t_dlist;

typedef void			(*t_data_apply)(void *);
typedef void			(*t_dnode_apply)(t_dlist *);
typedef void			(*t_lnode_apply)(t_list *);
typedef bool			(*t_data_is)(void *);

#endif
