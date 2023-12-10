/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:33:38 by iron              #+#    #+#             */
/*   Updated: 2023/12/10 13:04:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# define FTLIST_FAILURE EXIT_FAILURE
# define FTLIST_SUCCESS EXIT_SUCCESS

# include "ft_list_struct.h"
# include <stdbool.h>
# include <stddef.h>

typedef void	(*t_data_apply)(void *);
typedef void	(*t_dnode_apply)(t_dlist *);
typedef void	(*t_lnode_apply)(t_dlist *);
typedef bool	(*t_data_is)(void *);

/* ************************************************************************** */
/*                           SIMPLY LINKED LIST                               */
/* ************************************************************************** */

size_t			ft_list_dl_apply(t_dlist *start, t_data_apply applied);
size_t			ft_list_dl_apply_range(t_dlist *start, const t_dlist *end,
					t_data_apply applied);
size_t			ft_list_dl_apply_range_node(t_dlist *start, const t_dlist *end,
					t_dnode_apply applied);
size_t			ft_list_dl_clear(t_dlist *head, t_data_apply del);
size_t			ft_list_dl_clear_range(t_dlist *start, t_dlist *end,
					t_data_apply del);
t_dlist			*ft_list_dl_new(void);
t_dlist			*ft_list_dl_create(void *const data);
t_dlist			*ft_list_dl_copy_node(const t_dlist *const other);
t_dlist			*ft_list_dl_copy_list(const t_dlist *const other);
int				ft_list_dl_delete_self(t_dlist *node);
size_t			ft_list_dl_delete_range(t_dlist *start, t_dlist *target);
size_t			ft_list_dl_delete(t_dlist **head);
t_dlist			*ft_list_dl_find(t_dlist *head, void *data,
					int (*cmp)(void *content, void *data));
void			**ft_list_dl_get_datas(const t_dlist *src);
t_dlist			**ft_list_dl_get_nodes(const t_dlist *src);
t_dlist			*ft_list_dl_at(t_dlist *head, size_t index);
t_dlist			*ft_list_dl_end(t_dlist *head);
t_dlist			*ft_list_dl_begin(const t_dlist *head);
t_dlist			*ft_list_dl_push(t_dlist **node, t_dlist *added);
t_dlist			*ft_list_dl_push_back(t_dlist **node, t_dlist *added);
void			*ft_list_dl_pop(t_dlist **node);
void			*ft_list_dl_pop_back(t_dlist **node);
t_dlist			*ft_list_dl_subrange(t_dlist *src, t_dlist *to);
t_dlist			*ft_list_dl_subrange_to(t_dlist *head, t_dlist *end);
size_t			ft_list_dl_size(t_dlist *head);
size_t			ft_list_dl_size_of_data(t_dlist *head, t_data_is function);

void			ft_list_dl_add_back(t_dlist **head, t_dlist *added);
void			ft_list_dl_add_front(t_dlist **head, t_dlist *added);
void			ft_list_dl_rev(t_dlist **head);
t_dlist			*ft_list_dl_map(t_dlist *head, void *(*f)(void *),
					t_data_apply del);

/* ************************************************************************** */
/*                           SIMPLY LINKED LIST                               */
/* ************************************************************************** */

void			ft_listadd_back(t_list **lst, t_list *elem);
void			ft_listadd_front(t_list **lst, t_list *elem);
void			ft_listapply(t_list *lst, t_data_apply f);
void			ft_listapply_range(t_list *lst, const t_list *end,
					t_data_apply f);
void			ft_listapply_range_node(t_list *lst, const t_list *end,
					t_lnode_apply f);
void			ft_listclear(t_list **lst, t_data_apply del);
t_list			*ft_listcreate(const void *content);
t_list			*ft_listcreate_copy_node(t_list *lst);
t_list			*ft_listcreate_copy_node_list(t_list *lst);
void			ft_listdelone(t_list *lst, t_data_apply del);
size_t			ft_listdelete_range(t_list *start, const t_list *target,
					t_data_apply del);
void			*ft_listfind(t_list *list, void *data, int (*cmp)(void *content,
						void *data));
void			**ft_listget_datas(const t_list *src);
t_list			**ft_listget_nodes(const t_list *src);
t_list			*ft_listat(t_list *lst, size_t index);
t_list			*ft_listlast(t_list *lst);
t_list			*ft_listmap(t_list *lst, void *(*f)(void *), t_data_apply del);
t_list			*ft_listnew(void);
t_list			*ft_listpush(t_list **lst, t_list *elem);
t_list			*ft_listpush_back(t_list **lst, t_list *elem);
void			*ft_listpop(t_list **lst);
void			*ft_listpop_back(t_list **lst);
t_list			*ft_listrev(t_list **head);
size_t			ft_listsize(t_list *lst);
size_t			ft_listsize_match(t_list *lst, t_data_is function);
t_list			*ft_listsubrange(t_list *src, const t_list *to);

#endif
