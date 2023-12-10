/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:37:44 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 11:41:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_STRUCT_H
# define FT_LIST_STRUCT_H

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

#endif
