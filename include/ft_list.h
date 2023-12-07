/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:33:38 by iron              #+#    #+#             */
/*   Updated: 2023/12/07 10:40:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# define FTLIST_FAILURE EXIT_FAILURE
# define FTLIST_SUCCESS EXIT_SUCCESS

# include <stdbool.h>
# include <stddef.h>
# include "ft_list_struct.h"

typedef void			(*t_data_apply)(void *);
typedef void			(*t_node_apply)(t_dlist *);
typedef bool			(*t_data_is)(void *);

//	doubly linked list functions
size_t					ft_list_dl_apply(t_dlist *start, t_data_apply applied);
size_t					ft_list_dl_apply_range(t_dlist *start,
							const t_dlist *end, t_data_apply applied);
size_t					ft_list_dl_apply_range_node(t_dlist *start,
							const t_dlist *end, t_node_apply applied);
size_t					ft_list_dl_clear(t_dlist *head);
size_t					ft_list_dl_clear_range(t_dlist *start, t_dlist *end);
t_dlist					*ft_list_dl(void);
t_dlist					*ft_list_dl_create(void *const data);
t_dlist					*ft_list_dl_copy(const t_dlist *const other);
t_dlist					*ft_list_dl_copy_list(const t_dlist *const other);
int						ft_list_dl_delete_self(t_dlist *node);
size_t					ft_list_dl_delete_range(t_dlist *start,
							t_dlist *target);
size_t					ft_list_dl_delete(t_dlist **head);
size_t					ft_list_dl_delete_dup(t_dlist **src);
void					**ft_list_dl_get_datas(const t_dlist *src);
t_dlist					**ft_list_dl_get_nodes(const t_dlist *src);
t_dlist					*ft_list_dl_at(t_dlist *head, size_t index);
t_dlist					*ft_list_dl_end(t_dlist *head);
t_dlist					*ft_list_dl_begin(const t_dlist *head);
size_t					ft_list_dl_count(const t_dlist *head);
t_dlist					*ft_list_dl_push(t_dlist **node, t_dlist *added);
t_dlist					*ft_list_dl_push_back(t_dlist **node, t_dlist *added);
void					*ft_list_dl_pop(t_dlist **node);
void					*ft_list_dl_pop_back(t_dlist **node);
t_dlist					*ft_list_dl_subrange(t_dlist *src, t_dlist *to);
t_dlist					*ft_list_dl_subrange_to(t_dlist *head, t_dlist *end);
size_t					ft_list_dl_size(t_dlist *head);
size_t					ft_list_dl_size_of_data(t_dlist *head,
							t_data_is function);

// simply linked list
void					ft_listadd_back(t_list **lst, t_list *elem);
void					ft_listadd_front(t_list **lst, t_list *elem);
void					ft_listclear(t_list **lst, t_data_apply del);
void					ft_listdelone(t_list *lst, t_data_apply del);
void					ft_listiter(t_list *lst, t_data_apply f);
t_list					*ft_listlast(t_list *lst);
t_list					*ft_listrev(t_list **head);
t_list					*ft_listmap(t_list *lst, void *(*f)(void *),
							t_data_apply del);
t_list					*ft_listnew(const void *content);
int						ft_listsize(t_list *lst);

#endif
